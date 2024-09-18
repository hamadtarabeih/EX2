#include "Complex.cpp"
#include "Tree.cpp"
#include <iostream>
#include <map>

int main()
{
    // Integer Tree with new values
    Tree<int> intTree;
    intTree.add_root(10);
    intTree.add_sub_node(10, 20);
    intTree.add_sub_node(10, 30);
    intTree.add_sub_node(20, 40);
    intTree.add_sub_node(20, 50);
    intTree.add_sub_node(30, 60);
    intTree.add_sub_node(30, 70);

    std::cout << "Integer Tree Pre-Order Traversal: \n";
    Tree<int>::IteratorBase *i = intTree.begin_pre_order();
    while (i->hasNext())
    {
        std::cout << i->next() << " ";
    }
    delete i;
    std::cout << std::endl;

    // Complex Tree with new values
    Tree<Complex> complexTree;
    complexTree.add_root(Complex(2.0, 2.0));
    complexTree.add_sub_node(Complex(2.0, 2.0), Complex(4.0, 4.0));
    complexTree.add_sub_node(Complex(2.0, 2.0), Complex(6.0, 6.0));
    complexTree.add_sub_node(Complex(4.0, 4.0), Complex(8.0, 8.0));
    complexTree.add_sub_node(Complex(4.0, 4.0), Complex(10.0, 10.0));
    complexTree.add_sub_node(Complex(6.0, 6.0), Complex(12.0, 12.0));
    complexTree.add_sub_node(Complex(6.0, 6.0), Complex(14.0, 14.0));
    complexTree.add_sub_node(Complex(8.0, 8.0), Complex(16.0, 16.0));
    complexTree.add_sub_node(Complex(8.0, 8.0), Complex(18.0, 18.0));
    complexTree.add_sub_node(Complex(10.0, 10.0), Complex(20.0, 20.0));
    complexTree.add_sub_node(Complex(10.0, 10.0), Complex(22.0, 22.0));
    complexTree.add_sub_node(Complex(12.0, 12.0), Complex(24.0, 24.0));
    complexTree.add_sub_node(Complex(12.0, 12.0), Complex(26.0, 26.0));
    complexTree.add_sub_node(Complex(14.0, 14.0), Complex(28.0, 28.0));
    complexTree.add_sub_node(Complex(14.0, 14.0), Complex(30.0, 30.0));

    Tree<Complex, 2>::IteratorBase *it;
    std::cout << "Complex Tree Pre-Order Traversal: \n";
    it = complexTree.begin_pre_order();
    while (it->hasNext())
    {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Complex Tree Post-Order Traversal: \n";
    it = complexTree.begin_post_order();
    while (it->hasNext())
    {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Complex Tree In-Order Traversal: \n";
    it = complexTree.begin_in_order();
    while (it->hasNext())
    {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Complex Tree BFS Traversal: \n";
    it = complexTree.begin_bfs_scan();
    while (it->hasNext())
    {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Complex Tree DFS Traversal: \n";
    it = complexTree.begin_dfs_scan();
    while (it->hasNext())
    {
        std::cout << it->next() << " ";
    }
    delete it;
    std::cout << std::endl;

    std::cout << "Tree structure: " << std::endl;
    complexTree.print();

    return 0;
}
