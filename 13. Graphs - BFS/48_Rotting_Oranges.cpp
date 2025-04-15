#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, -1, 0, 1};

        queue<vector<int>> q;
        int freshOrange = 0;

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (grid[i][j] == 1)
                {
                    freshOrange++;
                }
                else if (grid[i][j] == 2)
                {
                    q.push({i, j, 0});
                }
            }
        }

        if (freshOrange == 0)
        {
            return 0;
        }

        int maxTime = 0;

        while (!q.empty())
        {
            vector<int> current = q.front();
            q.pop();

            int row = current[0];
            int col = current[1];
            int time = current[2];

            maxTime = max(maxTime, time);

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (newRow >= 0 && newRow < rowSize && newCol >= 0 && newCol < colSize && grid[newRow][newCol] == 1)
                {
                    grid[newRow][newCol] = 2;
                    freshOrange--;
                    q.push({newRow, newCol, time + 1});
                }
            }
        }

        if (freshOrange > 0)
        {
            return -1;
        }

        return maxTime;
    }
};

int main()
{
    vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};

    Solution solution;
    cout << solution.orangesRotting(grid);

    return 0;
}