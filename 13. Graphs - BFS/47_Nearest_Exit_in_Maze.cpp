#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int rowSize = maze.size();
        int colSize = maze[0].size();

        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, -1, 0, 1};

        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty())
        {
            vector<int> current = q.front();
            q.pop();

            int row = current[0];
            int col = current[1];
            int distance = current[2];

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize && maze[newRow][newCol] == '.')
                {
                    if (newRow == 0 || newRow == rowSize - 1 || newCol == 0 || newCol == colSize - 1)
                    {
                        return distance + 1;
                    }

                    maze[newRow][newCol] = '+';

                    q.push({newRow, newCol, distance + 1});
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}};
    vector<int> entrance = {1, 2};

    Solution solution;
    cout << solution.nearestExit(maze, entrance);

    return 0;
}