#pragma once
#include <iostream>
#include <vector>
#include <list>

using namespace std;
class edge{
    public:
    int q=0;
    int w=0;
    edge(int q, int w)
    {
        this->q = q;
        this->w = w;
    }
};
// A class that represents an undirected graph
class Graph
{
    int E;    // No. of vertices
    list<int>* adj;    // A dynamic array of adjacency lists
    void bRidgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent,int &count, vector<edge>& bridges);
public:
    Graph(int E);   // Constructor
    void addEdge(int q, int w);   // to add an edge to graph
    void bRidge();    // prints all bridges
    bool isConnected();
    void DFS(int v, std::vector<bool>& visited);
};