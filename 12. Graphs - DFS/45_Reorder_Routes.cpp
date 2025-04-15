#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> dirToUndir(int n, vector<vector<int>> arr)
    {
        vector<vector<int>> graph(n);

        for (int i = 0; i < arr.size(); i++)
        {
            int u = arr[i][0];
            int v = arr[i][1];

            graph[u].push_back(v);  // original direction: u -> v
            graph[v].push_back(-u); // reverse direction: v -> u (for traversal only)
        }

        return graph;
    }

    void dfsUtility(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &result, int &count)
    {
        if (visited[node] == true)
        {
            return;
        }

        result.push_back(node); // Not nenessary for this problem
        visited[node] = true;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int neighbour = abs(graph[node][i]);

            if (visited[neighbour] == false)
            {
                if (graph[node][i] > 0)
                {
                    count++;
                }

                dfsUtility(graph, neighbour, visited, result, count);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> graph = dirToUndir(n, connections);
        vector<int> result;
        vector<bool> visited(n, false);
        int count = 0;

        dfsUtility(graph, 0, visited, result, count);

        return count;
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};

    Solution solution;
    cout << solution.minReorder(6, arr);

    return 0;
}

// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/description/?envType=study-plan-v2&envId=leetcode-75