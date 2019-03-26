#include "Graph.hpp"
#include "utils.hpp"

using namespace DSA;

Vertex::Vertex(string name)
{
    title=name;
}

DirectedGraph_adjM::DirectedGraph_adjM(int size)
{
    num_vertices=0;
    max_vertices=size;

    vertices.resize(size);
    for (int push_iter=0; push_iter<size;++push_iter)
    {
        vertices[push_iter]=NULL;
    }

    marks.resize(size);

    int rows=size;
    int cols=size;
    edges.resize(rows, vector<int>(cols,0));

}

DirectedGraph_adjM::~DirectedGraph_adjM()
{
    for(int pop_iter=0;pop_iter<num_vertices;++pop_iter)
    {
        delete vertices[pop_iter];
    }
}

int DirectedGraph_adjM::getIndex(Vertex* vertex)
{
    int vert_idx=0;
    while(vert_idx<num_vertices)
    {
        if(vertices[vert_idx]==vertex)
        {
            return vert_idx;
        }
        vert_idx++;
    }
    return -1; //ideally never
}

int DirectedGraph_adjM::getWeight(int from_vertex, int to_vertex)
{
    int row=getIndex(vertices[from_vertex]);
    int col=getIndex(vertices[to_vertex]);
    return edges[row][col];
}

void DirectedGraph_adjM::addVertex(Vertex* vertex)
{
    vertices[num_vertices]=vertex;
    for(int matrix_iter=0;matrix_iter<max_vertices;++matrix_iter)
    {
        edges[num_vertices][matrix_iter]=0;
        edges[matrix_iter][num_vertices]=0;
    }
    num_vertices++;
}

void DirectedGraph_adjM::addEdge(int from_vertex, int to_vertex, int weight)
{
    int row=getIndex(vertices[from_vertex]);
    int col=getIndex(vertices[to_vertex]);
    edges[row][col]=weight;
}



bool DirectedGraph_adjM::isEmpty()
{
    if (num_vertices==0)
        return true;
    else
        return false;
}

bool DirectedGraph_adjM::isFull()
{
    if (num_vertices==max_vertices)
        return true;
    else
        return false;
}

void DirectedGraph_adjM::printGraph()
{
    for (int from_iter=0; from_iter<num_vertices; ++from_iter)
    {
        for(int to_iter=0; to_iter<num_vertices; ++to_iter)
        {
            if(getWeight(from_iter,to_iter)!=0)
                cout<<vertices[from_iter]->title<<"->"<<vertices[to_iter]->title<<endl;
        }
    }
}



