#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> pairs;

        for (int i = 0; i < nums1.size(); i++)
        {
            pairs.push_back({nums2[i], nums1[i]});
        }

        sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;

        for (int i = 0; i < k; i++)
        {
            sum += pairs[i].second;
            minHeap.push(pairs[i].second);
        }

        long long maxVal = sum * pairs[k - 1].first;

        for (int i = k; i < nums1.size(); i++)
        {
            if (pairs[i].second > minHeap.top())
            {
                sum -= minHeap.top();
                minHeap.pop();

                minHeap.push({pairs[i].second});
                sum += pairs[i].second;

                maxVal = max(maxVal, sum * pairs[i].first);
            }
        }

        return maxVal;
    }
};

int main()
{
    vector<int> nums1 = {1, 3, 3, 2}, nums2 = {2, 1, 3, 4};
    int k = 3;

    Solution solution;
    cout << solution.maxScore(nums1, nums2, k);

    return 0;
}

// https://leetcode.com/problems/maximum-subsequence-score/description/?envType=study-plan-v2&envId=leetcode-75