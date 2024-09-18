# Tree and Complex Classes

## Overview

This project implements two main components: a generic k-ary tree container and a complex number class, both in C++. The k-ary tree supports multiple types, including integers and complex numbers, and offers various traversal methods. The complex number class provides common operations such as addition, multiplication, and comparison.

## Features

- Generic k-ary Tree: Supports any type of keys (e.g., integers, complex numbers).
- Customizable k-value: The default is a binary tree (k=2), but you can set different values for k.
- Tree Traversals: Supports multiple traversal methods:
  - Pre-Order
  - Post-Order
  - In-Order
  - BFS (Breadth-First Search)
  - DFS (Depth-First Search)
- Iterators: Custom iterator implementations for each traversal method.
- Subtree Operations: Functions to add root and sub-nodes.
- Destructor: Ensures complete deletion of the tree to avoid memory leaks.
- Print Function: Displays the tree structure for easy visualization.


# Complex Class
  - Basic Arithmetic: Supports operations like addition, subtraction, multiplication, and division of complex numbers.
  - Comparison Operators: Implements comparison operators to check equality, greater than, and less than conditions.
  - Stream Overloading: Overloaded << operator to print complex numbers in the format [real, imaginary].
  - Input Handling: Overloaded >> operator for reading complex numbers from input.
  - Utility Functions: Magnitude and phase calculations for complex numbers.


## Usage

### Building

- Running Tree
To build the project, run the following command:

```bash
make
```

- Running Tests
tests by executing the following command:

```bash
make test
```
