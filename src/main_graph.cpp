#include <iostream>
#include "Graph.hpp"
#include "utils.hpp"

using namespace std;
using namespace DSA;
using namespace utils;

int main(int argc, char* argv[])
{
    cout<<"-----creating the following graph-------"<<endl;
    cout<<"A->B, A->C, B->D, D->C"<<endl;

    //TO DO: use smart pointers to avoid using new and delete (destructor)
    DirectedGraph_adjM graph(4);
    Vertex* root;
    Vertex* new_vertex;
    root=new Vertex("A");
    graph.addVertex(*root);
    new_vertex=new Vertex("B");
    graph.addVertex(*new_vertex);
    new_vertex=new Vertex("C");
    graph.addVertex(*new_vertex);
    new_vertex=new Vertex("D");
    graph.addVertex(*new_vertex);

    graph.addEdge(0,1,1);
    graph.addEdge(0,2,1);
    graph.addEdge(1,3,1);
    graph.addEdge(3,2,1);

    graph.printGraph();
    
    graph.BFS(*root);

    graph.DFS(*root);


}
