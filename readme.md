# C++ Library for Data Structures and Algorithms
(work in progress, stay tuned)
Uses STL wherever required/efficient
TO DO: make a class DSA and use polymorphism for rest of the data structures and have few basic virtual functions  (insertion, search, deletion)-- needs more thought
## Vectors

### Sorting:

quick sort: a divide and conquer algorithm. The worst case O(n2) occurs if pivot is always greatest/lowest.
            Average case: O(nlogn)
            in place sorting and cache friendly and therefore better than merge sort
            unstable by nature but can be modified to be stable
            better for arrays

merge sort: a divide and conquer algorithm. Stable Sorting algorithm. 
            better for linked lists

//insertion sort

//heap sort


### Searching:

Binary search: called binary because at every node you have two choices (binary choice)

(use data structures like map (Hash tables) to do searching)
(if possible, make a graph and use a graph search algorithm )

## Graphs

Undirected Graphs: undirected are basically directed graphs with two arrows in the opposite directions for each connection
weighted and unweighted graphs (assume all are weighted, if unweighted assume 1 or 0 as all weights)

Hence, weighted directed graphs are implemented for now.

Directed Graphs: both using adjacency matrix and adjacency list

all trees are also directed graphs but with no cycle:

//n-ary trees
//binary search tree
Binary Heap: Min Heap/Max Heap

### check if a graph is actually a tree (check for cycles):

### Graph Insertion:

### Minimum tree:
Kruskal minimum spanning tree

Prim's 

### Graph Search:
BFS: Uses queue. Note that the above code traverses only the vertices reachable from a given source vertex. All the vertices may not be reachable from a given vertex (example Disconnected graph). To print all the vertices, we can modify the BFS function to do traversal starting from all nodes one by one. Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph.

DFS: Uses stack data structure, Time Complexity: O(V+E) where V is number of vertices in the graph and E is number of edges in the graph. 
My implementation does recursively and hence doesn't need to use stack. TO DO: implement iterative DFS using stack (quite easy)

Dijkstra

A*

## Strings

### Compression Algorithm:
Huffman Coding

## Linked Lists

Singly linked lists

//doubly linked lists

### Sort:
Merge Sort

### Search

## Hash Tables (map)

