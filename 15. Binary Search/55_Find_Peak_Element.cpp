#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return 0;
        }
        else if (nums[0] > nums[1])
        {
            return 0;
        }
        else if (nums[n - 1] > nums[n - 2])
        {
            return n - 1;
        }

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (nums[mid] > nums[mid - 1])
            {
                low = mid + 1;
            }
            else if (nums[mid] > nums[mid + 1])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1; // high = mid - 1 will also work fine
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

    Solution solution;
    cout << solution.findPeakElement(nums);

    return 0;
}

// https://leetcode.com/problems/find-peak-element/description/?envType=study-plan-v2&envId=leetcode-75