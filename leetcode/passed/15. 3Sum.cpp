#include <bits/stdc++.h>
using namespace std;


namespace std {
    template<>
    struct hash<std::vector<int>> {
        size_t operator()(const std::vector<int>& v) const {
            size_t hash_val = 0;
            for (const auto& i : v) {
                hash_val ^= std::hash<int>()(i);
            }
            return hash_val;
        }
    };
}


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_set<vector<int>> ht;
        sort(nums.begin(), nums.end());

        for(size_t i{}; i < nums.size(); i++){
            if(i && nums[i] == nums[i - 1]) continue;
            size_t k {i + 1}, p {nums.size() - 1};
            while(k < p){
                if(nums[i] + nums[k] + nums[p] == 0){
                    ht.insert({nums[i], nums[k], nums[p]});
                    k++; p--;
                } 
                else if(nums[i] + nums[k] + nums[p] > 0) p--;
                else k++;
            }
        }
        for(auto vec: ht) ret.push_back(vec);
        return ret;
    }
}; 