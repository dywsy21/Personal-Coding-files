#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> queue;
        for(auto i: nums) queue.push(i);
        for(int i = 1; i < k; i++) queue.pop();
        return queue.top();









    }
};