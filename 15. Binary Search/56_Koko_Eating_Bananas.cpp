#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1; // Min 1 hour needed
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            long long hours = 0;

            for (auto pile : piles)
            {
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h)
            {
                result = mid;
                right = mid - 1; // This speed works, try a lower speed
            }
            else
            {
                left = mid + 1; // Speed is too slow, need a faster one
            }
        }

        return result;
    }
};

int main()
{
    vector<int> piles = {3,6,7,11};
    int h = 8;

    Solution solution;
    cout << solution.minEatingSpeed(piles, h);

    return 0;
}

// https://leetcode.com/problems/koko-eating-bananas/description/?envType=study-plan-v2&envId=leetcode-75