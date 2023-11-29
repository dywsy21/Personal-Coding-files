#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> deq;
        for(auto& num: nums) deq.push_back(num);
        k %= nums.size();
        for(size_t i = 0; i < k; i++){
            auto temp = deq.back();
            deq.pop_back();
            deq.push_front(temp);
        }

        nums.clear();
        for(auto num: deq) nums.push_back(num);
    }
};