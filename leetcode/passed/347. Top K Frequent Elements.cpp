#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second; // 降序排序
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++){
            if(hashmap.find(nums[i]) != hashmap.end()) hashmap[nums[i]]++;
            else hashmap.insert({nums[i], 1});
        }
        vector<pair<int, int>> pairs;
        for(auto pair: hashmap) pairs.emplace_back(pair);
        sort(pairs.begin(), pairs.end(), cmp);

        vector<int> ret;
        for(int i = 0; i < k; i++) ret.emplace_back(pairs[i].first);
        return ret;
    }
}