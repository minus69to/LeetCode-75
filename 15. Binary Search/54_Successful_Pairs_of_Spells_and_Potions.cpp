#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> result;

        sort(potions.begin(), potions.end());

        for(auto spell : spells)
        {
            long long minPotion = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            result.push_back(potions.end() - it);
        }

        return result;
    }
};

int main()
{
    vector<int> spells = {3, 1, 2}, potions = {8, 5, 8};
    int success = 16;

    Solution solution;
    vector<int> result = solution.successfulPairs(spells, potions, success);
    for(auto x : result)
    {
        cout << x << " ";
    }

    return 0;
}