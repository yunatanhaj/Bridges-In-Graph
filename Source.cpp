#include "Graph.h"

int main()
{
    int numberofvetices, numberofedges, v1, v2;
    char directed;


    cin >> numberofvetices;
    if (numberofvetices < 1) {
        cout << "Invalid Input";
        return 0;
    }
    Graph G = { numberofvetices };
    cin >> numberofedges;
    if (numberofedges < 0 || (numberofedges > ((numberofvetices) * (numberofvetices - 1)) / 2))
    {
        cout << "Invalid Input";
        return 0;

    }
    for (int i = 0; i < numberofedges; i++)
    {
        cin >> v1 >> v2;
        if (v1<1 || v1>numberofvetices || v2<1 || v2>numberofvetices)
        {
            cout << "Invalid Input";
            return 0;
        }
        G.addEdge(v1 - 1, v2 - 1);
    }
    if (!G.isConnected())
        cout << "Graph is not connected" << endl;
    else
        G.bRidge();
       // G.freeData();
    return 0;

}