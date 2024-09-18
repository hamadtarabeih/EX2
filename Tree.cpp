#include "Tree.hpp"
template <typename T, int K>
Tree<T, K>::Node::Node(T val): key(val), children(K, nullptr) {}

template <typename T, int K>
Tree<T,K>::PreOrderIterator::PreOrderIterator(Node *root) {
    if (root) stack.push(root);
}

template <typename T, int K>
bool Tree<T,K>::PreOrderIterator::hasNext() {
    bool hasNext = !stack.empty();
    return hasNext;
}

template <typename T, int K>
T Tree<T,K>::PreOrderIterator::next() {
    Node *node = stack.top();
    stack.pop();
    for (int i = K - 1; i >= 0; i--) {
        if (node->children[i])
            stack.push(node->children[i]);
    }
    return node->key;
}

template <typename T, int K>
Tree<T,K>::PostOrderIterator::PostOrderIterator(Node *root) {
    if (root)
        stack.push(root);

    while (!stack.empty()) {
        Node *node = stack.top();
        stack.pop();
        output.push(node);
        for (Node *child: node->children) {
            if (child)
                stack.push(child);
        }
    }
}

template <typename T, int K>
bool Tree<T,K>::PostOrderIterator::hasNext() {
    bool hasNext = !output.empty();
    return hasNext;
}

template <typename T, int K>
T Tree<T,K>::PostOrderIterator::next() {
    Node *node = output.top();
    output.pop();
    return node->key;
}

template <typename T, int K>
Tree<T,K>::InOrderIterator::InOrderIterator(Node *root): current(root) {}

template <typename T, int K>
bool Tree<T,K>::InOrderIterator::hasNext() {
    bool hasNext = current || !stack.empty();
    return hasNext;
}

template <typename T, int K>
T Tree<T,K>::InOrderIterator::InOrderIterator::next() {
    while (current) {
        stack.push(current);
        current = current->children[0];
    }
    current = stack.top();
    stack.pop();
    Node *node = current;
    if(current->children.size() > 1) current = current->children[1];
    else current = nullptr;
    return node->key;
}

template <typename T, int K>
Tree<T,K>::BFSIterator::BFSIterator(Node *root){
    if (root) queue.push(root);
}

template <typename T, int K>
bool Tree<T,K>::BFSIterator::hasNext() {
    return !queue.empty();
}

template <typename T, int K>
T Tree<T,K>::BFSIterator::next() {
    Node *node = queue.front();
    queue.pop();
    for (Node *child: node->children) {
        if (child) queue.push(child);
    }
    return node->key;
}

template <typename T, int K>
Tree<T,K>::DFSIterator::DFSIterator(Node *root) {
    if (root) stack.push(root);
}

template <typename T, int K>
bool Tree<T,K>::DFSIterator::hasNext() {
    bool hasNext = !stack.empty();
    return hasNext;
}

template <typename T, int K>
T Tree<T,K>::DFSIterator::next() {
    Node *node = stack.top();
    stack.pop();
    for (int i = K - 1; i >= 0; i--) {
        if (node->children[i])
            stack.push(node->children[i]);
    }
    return node->key;
}

template <typename T, int K>
Tree<T, K>::Tree(): root(nullptr) {}

template <typename T, int K>
Tree<T, K>::~Tree() {
    deleteSubTree(root);
}

template <typename T, int K>
void Tree<T, K>::add_root(T key) {
    if (!root) root = new Node(key);
    else root->key = key;
}

template <typename T, int K>
void Tree<T, K>::add_sub_node(T parent_key, T child_key) {
    Node *parent_node = findNode(root, parent_key);
    if (parent_node) {
        for (Node *&child: parent_node->children) {
            if (!child) {
                child = new Node(child_key);
                return;
            }
        }
        throw std::runtime_error("Reached maximum children");
    } else
        throw std::runtime_error("Parent not found");
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::begin_pre_order() {
    return new PreOrderIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::end_pre_order() {
    return nullptr;
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::begin_post_order() {
    return new PostOrderIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::end_post_order() {
    return nullptr;
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::begin_in_order() {
    return new InOrderIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::end_in_order() { 
    return nullptr;
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::begin_bfs_scan() {
    return new BFSIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::end_bfs_scan() {
    return nullptr;
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::begin_dfs_scan() {
    return new DFSIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase *Tree<T, K>::end_dfs_scan() {
    return nullptr;
}

template <typename T, int K>
Tree<T, K>::HeapIterator::HeapIterator(std::priority_queue<T, std::vector<T>, std::greater<T>> heap) 
    : heap(heap) {}
template <typename T, int K>
bool Tree<T, K>::HeapIterator::hasNext() {
    bool hasNext = !heap.empty();
    return hasNext;
}

template <typename T, int K>
T Tree<T, K>::HeapIterator::next() {
    if (!heap.empty()) {
        T value = heap.top();
        heap.pop();
        return value;
    }
    throw std::out_of_range("No more elements in heap");
}

template <typename T, int K>
typename Tree<T, K>::IteratorBase* Tree<T, K>::myHeap() {
    if (!root) return nullptr;

    std::priority_queue<T, std::vector<T>, std::greater<T>> minHeap;

    std::function<void(Node*)> addNodesToHeap = [&](Node* node) {
        if (node) {
            minHeap.push(node->key);
            for (Node* child : node->children) {
                addNodesToHeap(child);
            }
        }
    };

    addNodesToHeap(root);

    return new HeapIterator(minHeap);
}

template <typename T, int K>
void Tree<T, K>::print(Node *node, int depth, bool isLeft) const {
    if (node == nullptr) return;

    if (node->children.size() > 1 && node->children[1] != nullptr)
        print(node->children[1], depth + 1, false);

    for (int i = 0; i < depth; ++i)
        std::cout << "\t";
    if (depth > 0) {
        if(isLeft) std::cout << "└──";
        else std::cout << "┌──";
    }
    std::cout << node->key << std::endl;
    if (node->children.size() > 0 && node->children[0] != nullptr)
        print(node->children[0], depth + 1, true);
}

template <typename T, int K>
void Tree<T, K>::print() const {
    print(root);
}

template <typename T, int K>
typename Tree<T, K>::Node* Tree<T, K>::findNode(Node *node, T key) {
    if (!node)
        return nullptr;
    if (node->key == key)
        return node;
    for (Node *child: node->children) {
        Node *found = findNode(child, key);
        if (found)
            return found;
    }
    return nullptr;
}

template <typename T, int K>
void Tree<T, K>::deleteSubTree(Node *node){
    if (!node)
        return;
    for (Node *child: node->children) {
        deleteSubTree(child);
    }
    delete node;
}