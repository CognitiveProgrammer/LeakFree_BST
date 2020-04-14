# LeakFree BST(Binary Search Tree0 in C++
# A Leak Free, High Performance C++ Binary Search Tree (BST) using STL containers like Vector / Deque

Any Binary Search Tree (BST) creation in C/C++ requires lots of memory allocations an de-allocations. This is often done by using pointers which leads to complex pointer management, errors and more specifically the memory leaks

In case we need to create a small Binary Search Tree(BST), we can create a BST using `std::vector` or `std::deque`.  These BST can be deleted at once without bothering about deleting individual elements.

## Exception

We can't use this BST for deleting certain elements from the tree because it will not re-align the memory and will be slow.


## Suited For

1. If the code needs to keep the data in sorted order
2. Data grows over a period of time
3. There is a need to clean the tree at one go.

## NOTE

- STL `std::set` and `std::map` can (and in many conditions should) also be used for stroing data in sorted orders. How this `std::vector` based code works better and in many cases faster than these containers.
- This code works best with small set of data, especially if the data itself is having low footprint.

# The Implementation

The code is implemented using vector indexes instead of next pointers to store the location of left and right subtree.

![bst_implementation](https://github.com/CodesBay/LeakFree_BST/blob/master/BST%20Implementation.jpg)
