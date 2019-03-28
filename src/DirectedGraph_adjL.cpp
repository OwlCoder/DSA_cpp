#include "DirectedGraph_adjL.hpp"

using namespace DSA;

DirectedGraph_adjL::DirectedGraph_adjL(const vector<Edge>& edges, int size)
{
    _size=size;
    _adj_list.resize(size);
    for (auto& edge: edges)
    {
        int src=edge.src;
        int dest=edge.dst;
        int weight=edge.weight;

        _adj_list[src].push_back(make_pair(dest,weight));
    }
}

DirectedGraph_adjL::~DirectedGraph_adjL()
{

}

void DirectedGraph_adjL::printGraph()
{
    for(int row_iter=0; row_iter<_size; ++row_iter)
    {
        for (Pair vertex: _adj_list[row_iter])
        {
            cout<<"("<<row_iter<<", "<<vertex.first<<", "<<vertex.second<<") ";
        }
        cout<<endl;
    }
}