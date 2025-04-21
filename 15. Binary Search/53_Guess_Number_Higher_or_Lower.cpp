#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1;
        int right = n;

        while (right >= left)
        {
            int mid = left + (right - left) / 2;
            int result = guess(mid);

            if (result == 0)
            {
                return mid;
            }
            else if (result == -1)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}

// https://leetcode.com/problems/guess-number-higher-or-lower/description/?envType=study-plan-v2&envId=leetcode-75