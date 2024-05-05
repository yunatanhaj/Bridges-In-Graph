#include "Graph.h"


Graph::Graph(int E)
{
    this->E = E;
    adj = new list<int>[E];
}

void Graph::addEdge(int q, int w)
{
    adj[q].push_back(w);
    adj[w].push_back(q);  // Note: the graph is undirected
}


void Graph::bRidgeUtil(int u, vector<bool>& visited, vector<int>& disq,
    vector<int>& low, int parent,int& count, vector<edge>& bridges)
{
   vector<edge> lowq;
    
   
    static int time = 0;


    visited[u] = true;

 
    disq[u] = low[u] = ++time;


    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i; 

        if (v == parent)
            continue;


        if (visited[v]) {
            low[u] = min(low[u], disq[v]);
        }


        else {
            parent = u;
          
            bRidgeUtil(v, visited, disq, low, parent,count,bridges);

            
            low[u] = min(low[u], low[v]);
            if (low[v] > disq[u]) {
                edge e(u + 1, v + 1);
                bridges.push_back(e);
                count++;
            }

            
            }
   
        }
    }




void Graph::bRidge()
{
  
    vector<bool> visited(E, false);
    vector<int> disc(E, -1);
    vector<int> low(E, -1);
    vector<edge> bridges;
    int count = 0;
    int parent = -1;

    for (int i = 0; i <E; i++)
        if (visited[i] == false)
            bRidgeUtil(i, visited, disc, low, parent,count,bridges);

    if (count == 0)
        cout << "No bridges in graph" << endl;
    else {
        for (int z = bridges.size() - 1; z >= 0; z--)
        {
            cout << bridges[z].q << " " << bridges[z].w << endl;
        }
    }

}
bool Graph::isConnected()
{
    std::vector<bool> visited(E, false);
    DFS(0, visited);

    for (bool vertexVisited : visited)
    {
        if (!vertexVisited)
            return false;
    }

    return true;
}

void Graph::DFS(int v, std::vector<bool>& visited)
{
    visited[v] = true;

    for (int neighbor : adj[v])
    {
        if (!visited[neighbor])
            DFS(neighbor, visited);
    }
}