#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> nums_set;
        int maxStreak {};
        for(const auto& num: nums) nums_set.insert(num);

        for(const auto& num: nums_set){
            if(!nums_set.count(num - 1)){
                int cur_num = num;
                int cur_Streak = 0;

                while(nums_set.count(cur_num)){
                    cur_num++; cur_Streak++;
                }
                maxStreak = max(maxStreak, cur_Streak);
            }
        }
        return maxStreak;
    }
};