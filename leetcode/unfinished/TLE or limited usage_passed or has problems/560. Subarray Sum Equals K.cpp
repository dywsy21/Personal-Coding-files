#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret{};
        for(int len{}; len <= nums.size(); len++){
            int sum{};
            for(int i{}; i < len - 1; i++) sum += nums[i];
            for(int i{}; i + len - 1 < nums.size(); i++){
                if(i) sum -= nums[i - 1];
                sum += nums[i + len -1];
                if(sum == k) ret++;
            }
        }
        return ret;
    }
};