#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

class Graph{
    bool **adjMatrix;
    int vertexCount;
    int *parent;
    int *state;
    int *level;
public:
    Graph(int vertexCount);
    ~Graph();
    void addEdge(int i,int j);
    void bfs();
    void print();
};
Graph::Graph(int vc)
{
    this->parent = new int [vc];
    this->state = new int [vc];
    this->level = new int [vc];
    this->vertexCount = vc;

    adjMatrix = new bool* [vc];
    for(int i=0;i<vc;i++)
    {
        adjMatrix[i] = new bool [vc];
        for(int j=0;j<vc;j++)
            adjMatrix[i][j] = false;
    }

}
Graph::~Graph()
{
    delete [] adjMatrix;
    delete [] parent;
    delete [] state;
    delete [] level;
}
void Graph::addEdge(int i,int j)
{
    if(i>=0&&i<this->vertexCount&&j>=0&&j<this->vertexCount)
    {
        this->adjMatrix[i][j]=true;
        this->adjMatrix[j][i]=true;
    }
}
void Graph::bfs()
{
    for(int i=0;i<vertexCount;i++)
    {
        state[i] = 0;
        parent[i] = 0;
    }
    int lvl = 0;
    state[0] = 1;
    parent[0] = 0;
    level[0] = lvl;
    queue<int> q;
    q.push(0);
    lvl++;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<vertexCount;i++)
        {
            if(adjMatrix[u][i]&&state[i]==0)
            {
                q.push(i);
                state[i] = 1;
                parent[i] = u;
                level[i] = lvl;
            }
        }
        lvl++;
        state[u] = 2;
    }
}
void Graph::print()
{
    int lvl,sn;
    while(true)
    {
        cout<<"Level : ";
        cin>>lvl;
        cout<<"\nStart Nod : ";
        cin>>sn;
        printf("\n");
        for(int i=0;i<vertexCount;i++)
        {
            if(parent[i]==sn&&level[i]==lvl)
            {
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}
int main()
{
    Graph g(9);
    g.addEdge(0,1); g.addEdge(1,2);
    g.addEdge(0,3); g.addEdge(1,3);
    g.addEdge(0,1); g.addEdge(1,4);
    g.addEdge(2,4); g.addEdge(3,4);
    g.addEdge(3,5); g.addEdge(5,7);
    g.addEdge(5,6); g.addEdge(6,7);
    g.addEdge(4,6); g.addEdge(7,8);
    g.addEdge(4,8); g.addEdge(6,8);
    g.bfs();
    g.print();
    return 0;
}
