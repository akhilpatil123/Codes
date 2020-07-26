#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void showGraph(vector<int> adjList[], int V)
{
    for(int u=0; u<V; u++)
    {
        cout<<"Vertex:"<<u<<endl<<"head";
        for(int v=0; v<adjList[u].size(); v++)
        {
            cout<<"->"<<adjList[u][v];
        }
        cout<<endl;
    }
}

int main() {
    
    int V=5;
    vector<int> adjList[V];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 3, 4);
    showGraph(adjList, V);
	return 0;
}
