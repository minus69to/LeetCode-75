#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
    int currentMin;                                         // Tracks the smallest number not yet popped
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for added-back numbers
    unordered_set<int> numbersInHeap;                       // To quickly check if a number is in the heap

public:
    SmallestInfiniteSet()
    {
        currentMin = 1;
    }

    int popSmallest()
    {
        if (!minHeap.empty())
        {
            int smallest = minHeap.top();
            minHeap.pop();
            numbersInHeap.erase(smallest);

            return smallest;
        }
        else
        {
            return currentMin++;
        }
    }

    void addBack(int num)
    {
        if (num < currentMin && numbersInHeap.find(num) == numbersInHeap.end())
        {
            minHeap.push(num);
            numbersInHeap.insert(num);
        }
        }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main()
{
    vector<string> results;

    SmallestInfiniteSet *obj = new SmallestInfiniteSet();
    results.push_back("null"); // Result for constructor

    obj->addBack(2);
    results.push_back("null");

    int result1 = obj->popSmallest();
    results.push_back(to_string(result1));

    int result2 = obj->popSmallest();
    results.push_back(to_string(result2));

    int result3 = obj->popSmallest();
    results.push_back(to_string(result3));

    obj->addBack(1);
    results.push_back("null");

    int result4 = obj->popSmallest();
    results.push_back(to_string(result4));

    int result5 = obj->popSmallest();
    results.push_back(to_string(result5));

    int result6 = obj->popSmallest();
    results.push_back(to_string(result6));

    cout << "[" << results[0] << "," << results[1] << "," << results[2] << ","
         << results[3] << "," << results[4] << "," << results[5] << ","
         << results[6] << "," << results[7] << "," << results[8] << "]" << endl;

    return 0;
}

// https://leetcode.com/problems/smallest-number-in-infinite-set/description/?envType=study-plan-v2&envId=leetcode-75