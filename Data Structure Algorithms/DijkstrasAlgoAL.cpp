/*
PROBLEM : IMPLEMENTATION OF DIJKSTRA'S ALGORITHM IN ADJACENCY LIST REPRESENTATION OF GRAPH
BY : SONAL DUBEY
*/
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V, E;
    vector<pair <int,int> > *adj;

    public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<pair<int,int> >[V];
    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void printgraph(int p)
{
    
    for(int i=0; i<p; i++)
    {
        cout << i<< "-->";
        cout << endl;
        for(auto j : adj[i])
        {
            cout << "Connected with node " << j.first << " with weight " << j.second << "\n";
        }
        cout << endl;
    }
}
 
};

int main()
{
    int n,e;
    cin >> n >> e;
    Graph g(n);
    for(int i=0; i< e; i++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            g.add_edge(u,v,w);
        }

    
    return 0;
}

/*
Here is a sample test case you can try : 
9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
8 6 6
8 2 2
2 5 4
6 5 2
2 3 7
5 3 14
3 4 9 
5 4 10
*/