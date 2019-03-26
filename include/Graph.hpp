#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

namespace DSA
{
    class Vertex
    {
        //public variables
        public:
            string title;

        //public functions
        public:
            Vertex(string name);

    };

    //implemented using adjacency matrix
    class DirectedGraph_adjM
    {
        //public variables
        public:


        //public functions
        public:
            // constructor
            DirectedGraph_adjM(int size);
            // destructor
            ~DirectedGraph_adjM();
            
            // add a vertex to the adjacency matrix
            void addVertex(Vertex* vertex);
            // add weight to the adjacency matrix at (from_vertex, to_vertex)
            void addEdge(int from_vertex, int to_vertex, int weight);            
            
            // print the graph
            void printGraph();
            
            //search algorithms

            /*
            Breadth first Search: Use queue
            */
		    void BFS(Vertex* vertex);

            /*
            Depth First Search
            */
		   	void DFS(Vertex* vertex);


        //private variables
        private:
            int num_vertices;
            int max_vertices;
            vector<Vertex*> vertices;
            vector<bool> marks;
            vector<vector<int>> edges;


        //private functions
        private:

            // get index of the vertex from the adjacency matrix 
            int getIndex(Vertex* vertex);
            // get weight of the vertex from the adjacency matrix
            int getWeight(int from_vertex, int to_vertex);
            // check if we have added all the vertices to the adjacency matrix
            bool isFull();
            // check if the adjacency matrix has no vertices
            bool isEmpty();

    };

    //implemented using adjacency list
    class DirectedGraph_adjL
    {

    };

    //implemented using adjacency matrix
    class UnDirectedGraph_adjM
    {

    };


    class BinarySearchTree
    {

    };

}// end of ns DSA