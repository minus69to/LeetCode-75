#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfsUtility(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<int> &result)
    {
        if (visited[node] == true)
        {
            return;
        }

        result.push_back(node);
        visited[node] = true;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int neighbour = graph[node][i];
            if (visited[neighbour] == false)
            {
                dfsUtility(graph, neighbour, visited, result);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<int> result;
        vector<bool> visited(rooms.size(), false);

        dfsUtility(rooms, 0, visited, result);

        for (auto x : visited)
        {
            if (x == false)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 3}, {3, 0, 1}, {2}, {0}};

    Solution solution;
    cout << solution.canVisitAllRooms(arr);

    return 0;
}