#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

namespace DSA
{
    struct Edge
    {
        int src,dst,weight;
    };

    class DirectedGraph_adjL
    {
        //public variables
        public:
            //pair of dst and weight
            typedef pair<int,int> Pair;

        //public functions
        public:
            DirectedGraph_adjL(const vector<Edge>& edges, int size);
            ~DirectedGraph_adjL();

            void printGraph();

        //private variables
        private:
            vector<vector<Pair>> _adj_list;
            int _size;


        //private functions
        private:

    };// end of main class

}// end of ns DSA