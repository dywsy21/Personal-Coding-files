#include <bits/stdc++.h>
using namespace std;

int left_search(vector<int>& nums, int target, int left, int right){
cout << "In left search:" << left << " " << right << endl;
    if(!right || nums[right - 1] != target) return right;

    int mid = (left + right) / 2;
    if(nums[mid] < target) return left_search(nums, target, mid, right);
    else return left_search(nums, target, left, mid);
}

int right_search(vector<int>& nums, int target, int left, int right){
cout << "In right search:" << left << " " << right << endl;

    if(left == nums.size() - 2 || nums[left + 1] != target) return left;

    int mid = (left + right) / 2;
    if(nums[mid] < target) return right_search(nums, target, left, mid);
    else return right_search(nums, target, mid, right);
}


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1, flag = 0;
        while(left < right){
            if(nums[left] == target || nums[right] == target){
                flag = 1;
                break;
            }
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid + 1;
            if(nums[mid] > target) right = mid - 1;
            if(nums[mid] == target) right = mid;
        }
cout << "before entering left-right search:" << left << " " << right << endl;

        if(!flag) return {-1,-1};
        return {right_search(nums, target, 0, right), left_search(nums, target, right, nums.size()-1)};
    }
};