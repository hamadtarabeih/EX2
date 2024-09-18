#ifndef TREE_H
#define TREE_H

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <vector>
#include <functional>

template <typename T, int K = 2>
class Tree {
public:
    class Node {
    public:
        T key;
        std::vector<Node *> children;
        Node(T val);
    };

    class IteratorBase {
    public:
        virtual ~IteratorBase() {}
        virtual bool hasNext() = 0;
        virtual T next() = 0;
    };

    class PreOrderIterator : public IteratorBase {
    private:
        std::stack<Node *> stack;

    public:
        PreOrderIterator(Node *root);

        bool hasNext() override;

        T next() override;
    };

    class PostOrderIterator : public IteratorBase {
    private:
        std::stack<Node *> stack;
        std::stack<Node *> output;

    public:
        PostOrderIterator(Node *root);

        bool hasNext() override;

        T next() override;
    };

    class InOrderIterator : public IteratorBase {
    private:
        std::stack<Node *> stack;
        Node *current;

    public:
        InOrderIterator(Node *root);

        bool hasNext() override;

        T next() override;
    };

    class BFSIterator : public IteratorBase {
    private:
        std::queue<Node *> queue;

    public:
        BFSIterator(Node *root);
        bool hasNext() override;
        T next() override;
    };

    class DFSIterator : public IteratorBase {
    private:
        std::stack<Node *> stack;

    public:
        DFSIterator(Node *root);
        bool hasNext() override;
        T next() override;
    };
    
    class HeapIterator : public IteratorBase {
    private:
        std::priority_queue<T, std::vector<T>, std::greater<T>> heap;
    public:
        HeapIterator(std::priority_queue<T, std::vector<T>, std::greater<T>> heap);
        bool hasNext() override;
        T next() override;
    };

    Tree();
    ~Tree();
    void add_root(T key);
    void add_sub_node(T parent_key, T child_key);
    IteratorBase *begin_pre_order();
    IteratorBase *end_pre_order();
    IteratorBase *begin_post_order();
    IteratorBase *end_post_order();
    IteratorBase *begin_in_order();
    IteratorBase *end_in_order();
    IteratorBase *begin_bfs_scan();
    IteratorBase *end_bfs_scan();
    IteratorBase *begin_dfs_scan();
    IteratorBase *end_dfs_scan();
    IteratorBase* myHeap();
    void print(Node *node, int depth = 0, bool isLeft = true) const;
    void print() const;
private:
    Node *root;
    Node *findNode(Node *node, T key);
    void deleteSubTree(Node *node);
};

#endif // TREE_H
