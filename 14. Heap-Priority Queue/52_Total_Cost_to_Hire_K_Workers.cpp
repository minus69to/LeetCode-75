#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> leftHeap;
        priority_queue<int, vector<int>, greater<int>> rightHeap;

        int left = 0;
        int right = costs.size() - 1;
        long long cost = 0;

        while (left < candidates)
        {
            leftHeap.push(costs[left++]);
        }

        while (right >= left && right >= costs.size() - candidates)
        {
            rightHeap.push(costs[right--]);
        }

        for (int i = 0; i < k; i++)
        {
            if (leftHeap.empty())
            {
                cost += rightHeap.top();
                rightHeap.pop();

                if (right >= left)
                {
                    rightHeap.push(costs[right--]);
                }
                continue;
            }

            if (rightHeap.empty())
            {
                cost += leftHeap.top();
                leftHeap.pop();

                if (left <= right)
                {
                    leftHeap.push(costs[left++]);
                }
                continue;
            }

            if (leftHeap.top() <= rightHeap.top())
            {
                cost += leftHeap.top();
                leftHeap.pop();

                if (left <= right)
                {
                    leftHeap.push(costs[left++]);
                }
            }
            else
            {
                cost += rightHeap.top();
                rightHeap.pop();

                if (right >= left)
                {
                    rightHeap.push(costs[right--]);
                }
            }
        }

        return cost;
    }
};

int main()
{
    vector<int> costs = {1,2,4,1};
    int k = 3, candidates = 3;

    Solution solution;
    cout << solution.totalCost(costs, k, candidates);

    return 0;
}

// https://leetcode.com/problems/total-cost-to-hire-k-workers/description/?envType=study-plan-v2&envId=leetcode-75