#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre {nums[0]}, ret {nums[0]};
        for(size_t i {1}; i < nums.size(); i++){
            pre = max(pre + nums[i], nums[i]);
            ret = max(ret, pre);
        }
        return ret;
    }
};