#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<string, vector<string>> graph;
    unordered_map<string, vector<double>> weights;

    void buildGraph(vector<vector<string>> &equations, vector<double> &values)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];

            graph[u].push_back(v);
            weights[u].push_back(w);

            graph[v].push_back(u);
            weights[v].push_back(1.0 / w);
        }
    }

    void dfsUtility(string node, string target, unordered_map<string, bool> &visited, double &result, double value, bool &found)
    {
        if (visited[node] == true)
        {
            return;
        }

        visited[node] = true;
        if (node == target)
        {
            result = value;
            found = true;
            return;
        }

        for (int i = 0; i < graph[node].size(); i++)
        {
            string neighbour = graph[node][i];
            double weight = weights[node][i];

            if (visited[neighbour] == false)
            {
                dfsUtility(neighbour, target, visited, result, value * weight, found);

                if (found)
                {
                    return;
                }
            }
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        buildGraph(equations, values);
        vector<double> results;

        for (int i = 0; i < queries.size(); i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];

            if (graph.find(start) == graph.end() || graph.find(end) == graph.end())
            {
                results.push_back(-1.0);
                continue;
            }

            unordered_map<string, bool> visited;
            double result = -1.0;
            bool found = false;

            dfsUtility(start, end, visited, result, 1, found);
            results.push_back(result);
        }

        return results;
    }
};

int main()
{
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> values = {1.5, 2.5, 5.0};
    vector<vector<string>> queries = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};

    // Output: [3.75000, 0.40000, 5.00000, 0.20000]

    Solution solution;
    vector<double> ans = solution.calcEquation(equations, values, queries);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

// https://leetcode.com/problems/evaluate-division/description/?envType=study-plan-v2&envId=leetcode-75