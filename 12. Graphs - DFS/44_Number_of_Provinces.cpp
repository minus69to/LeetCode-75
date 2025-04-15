#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfsUtility(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &result)
    {
        if (visited[node] == true)
        {
            return;
        }

        result.push_back(node);
        visited[node] = true;

        for (int neighbour = 0; neighbour < graph[node].size(); neighbour++)
        {
            if (graph[node][neighbour] == 1 && visited[neighbour] == false)
            {
                dfsUtility(graph, neighbour, visited, result);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> result;
        vector<bool> visited(isConnected.size(), false);

        int count = 0;

        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                count++;
                dfsUtility(isConnected, i, visited, result);
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    Solution solution;
    cout << solution.findCircleNum(arr);

    return 0;
}