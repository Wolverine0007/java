#include <iostream>
#include <climits>
using namespace std;
class graph
{
public:
    int v;
    int e;
    int adjMatrix[20][20];
    graph(int vertices, int edges)
    {
        v = vertices;
        e = edges;
        for (inft i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void acceptGraph();
    void displayGraph();
    int prims_mst();
};
void graph::acceptGraph()
{
    for (int i = 0; i < e; i++)
    {
        int v1, v2, wt;
        cout << "\nEnter vertex v1, v2, and weight of the edge: ";
        cin >> v1 >> v2 >> wt;
        adjMatrix[v1][v2] = wt;
        adjMatrix[v2][v1] = wt;
    }
}
void graph::displayGraph()
{
    cout << "\nAdjacency Matrix of the Graph: \n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}


int graph::prims_mst()
{
    int selected[v];
    int parent[v];
    int key[v];
    for (int i = 0; i < v; i++)
    {
        key[i] = INT_MAX;
        selected[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    int totalWeight = 0;
    for (int count = 0; count < v ; count++)
    {
        int minKey = INT_MAX, minIndex;
        for (int i = 0; i < v; i++)
        {
            if (selected[i] == false && key[i] < minKey)
            {
                minKey = key[i];
                minIndex = i;
            }
        }
        int u = minIndex;
        selected[u] = true;
        totalWeight += key[u];
        for (int v = 0; v < this->v; v++)
        {
            if (adjMatrix[u][v] && selected[v] == false && adjMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adjMatrix[u][v];
            }
        }
    }
    return totalWeight;
}
int main()
{
    int v, e;
    cout << "\nEnter total no. of vertices: ";
    cin >> v;
    cout << "\nEnter total no. of edges: ";
    cin >> e;
    graph g(v, e);
    g.acceptGraph();
    g.displayGraph();
    int totalWeight = g.prims_mst();
    cout << "\nTotal weight of the minimum spanning tree (MST): " << totalWeight << endl;
    return 0;
}
//Output-
// Enter total no. of vertices: 5
// Enter total no. of edges: 7
// Enter vertex v1, v2, and weight of the edge: 0 1 4
// Enter vertex v1, v2, and weight of the edge: 0 2 8
// Enter vertex v1, v2, and weight of the edge: 1 2 2
// Enter vertex v1, v2, and weight of the edge: 1 3 6
// Enter vertex v1, v2, and weight of the edge: 2 3 3
// Enter vertex v1, v2, and weight of the edge: 2 4 9
// Enter vertex v1, v2, and weight of the edge: 3 4 5
// Adjacency Matrix of the Graph:
// 0 4 8 0 0
// 4 0 2 6 0
// 8 2 0 3 9
// 0 6 3 0 5
// 0 0 9 5 0
// Total weight of the minimum spanning tree (MST): 9