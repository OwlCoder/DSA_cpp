#include "DirectedGraph_adjM.hpp"
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


void DirectedGraph_adjM::addVertex(Vertex& vertex)
{
    vertices.push_back(&vertex);
    for(int matrix_iter=0;matrix_iter<max_vertices;++matrix_iter)
    {
        edges[num_vertices][matrix_iter]=0;
        edges[matrix_iter][num_vertices]=0;
    }
    num_vertices++;
}

void DirectedGraph_adjM::addEdge(int from_vertex, int to_vertex, int weight)
{
    int row=getIndex(*vertices[from_vertex]);
    int col=getIndex(*vertices[to_vertex]);
    edges[row][col]=weight;
}

void DirectedGraph_adjM::printGraph()
{
    cout<<"printing the graph constructed:  ";
    for (int from_iter=0; from_iter<num_vertices; ++from_iter)
    {
        for(int to_iter=0; to_iter<num_vertices; ++to_iter)
        {
            if(getWeight(from_iter,to_iter)!=0)
                cout<<vertices[from_iter]->title<<"->"<<vertices[to_iter]->title<<", ";
        }
    }
    cout<<endl;
}

void DirectedGraph_adjM::BFS(Vertex& vertex)
{
    //set all marks to false
    for (int marks_iter=0; marks_iter<num_vertices; ++marks_iter)
        marks[marks_iter]=false;
    // FIFO structure
    queue<Vertex*> q;
    int curr_idx= getIndex(vertex);
    // mark it as visited
    marks[curr_idx]=true;
    q.push(&vertex);
    cout<<"BFS: ";
    while (!q.empty())
    {
        Vertex* curr_node= q.front();
        q.pop();
        curr_idx=getIndex(*curr_node);
        cout << curr_node->title << " ";
        // get all adjacent vertices of the curr_vertex
        for (int adj_iter=0; adj_iter<num_vertices; ++adj_iter)
        {
            int adj_idx=getIndex(*vertices[adj_iter]);
            if(edges[curr_idx][adj_idx]!=0)
            {
                if(marks[adj_iter]==false)
                {
                    marks[adj_iter]=true;
                    q.push(vertices[adj_iter]);
                }
            }
        }
    }
    cout<<endl;
}

void DirectedGraph_adjM::DFS(Vertex& vertex)
{
    //set all marks to false
    for (int marks_iter=0; marks_iter<num_vertices; ++marks_iter)
        marks[marks_iter]=false;
    cout<<"DFS: ";
    
    DFSUtil(&vertex);

    cout<<endl;

}

//private functions
int DirectedGraph_adjM::getIndex(const Vertex& vertex)
{
    int vert_idx=0;
    while(vert_idx<num_vertices)
    {
        if(vertices[vert_idx]==&vertex)
        {
            return vert_idx;
        }
        vert_idx++;
    }
    return -1; //ideally never
}

int DirectedGraph_adjM::getWeight(int from_vertex, int to_vertex)
{
    int row=getIndex(*vertices[from_vertex]);
    int col=getIndex(*vertices[to_vertex]);
    return edges[row][col];
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

void DirectedGraph_adjM::DFSUtil(Vertex* vertex)
{
    if (vertex==NULL)
        return;

    cout<<vertex->title<<" ";
    int curr_idx, adj_idx;
    curr_idx=getIndex(*vertex);
    marks[curr_idx]=true;

    for (int adj_iter=0; adj_iter<num_vertices; ++adj_iter)
    {
        adj_idx=getIndex(*vertices[adj_iter]);
        if (edges[curr_idx][adj_idx]!=0)
        {
            if(marks[adj_idx]==false)
            {
                DFSUtil(vertices[adj_idx]);
            }
        }
    }
}