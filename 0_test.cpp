#include <iostream>
#include <vector>

using namespace std;

// Create directed weighted graph using vector<vector<vector<int>>>
vector<vector<vector<int>>> createDirectedWeightedGraph(int vertices, vector<vector<int>> &edges)
{
    vector<vector<vector<int>>> graph(vertices);

    for (int i = 0; i < edges.size(); ++i)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];

        vector<int> edge;

        edge.push_back(to);
        edge.push_back(weight);
        graph[from].push_back(edge);
    }

    return graph;
}

// DFS helper
void dfsUtil(int node, vector<vector<vector<int>>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < graph[node].size(); ++i)
    {
        int neighbor = graph[node][i][0];
        if (!visited[neighbor])
        {
            dfsUtil(neighbor, graph, visited);
        }
    }
}

// DFS from a given start node
void dfs(int start, vector<vector<vector<int>>> &graph)
{
    vector<bool> visited(graph.size(), false);
    cout << "DFS starting from node " << start << ": ";
    dfsUtil(start, graph, visited);
    cout << endl;
}

// Print the graph
void printGraph(vector<vector<vector<int>>> &graph)
{
    for (int u = 0; u < graph.size(); ++u)
    {
        cout << "Vertex " << u << ":";
        for (int j = 0; j < graph[u].size(); ++j)
        {
            int v = graph[u][j][0];
            int w = graph[u][j][1];
            cout << " -> (" << v << ", weight: " << w << ")";
        }
        cout << endl;
    }
}

// Main
int main()
{
    int numVertices = 5;

    // Each edge: {from, to, weight}
    vector<vector<int>> edgeList;
    edgeList.push_back({0, 1, 10});
    edgeList.push_back({0, 4, 20});
    edgeList.push_back({1, 2, 30});
    edgeList.push_back({1, 3, 40});
    edgeList.push_back({2, 3, 50});
    edgeList.push_back({3, 4, 60});

    vector<vector<vector<int>>> graph = createDirectedWeightedGraph(numVertices, edgeList);

    printGraph(graph);
    dfs(0, graph);

    return 0;
}
