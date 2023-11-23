#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;

        for(int i=0; i<nums.size(); i++){
            auto cur = hashtable.find(target - nums[i]);
            if(cur != hashtable.end()) return {i, cur->second};
            hashtable[nums[i]] = i;
        }

        return {};
    }
};