package leetcode.passed;
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] nums1_copy = new int[m];
        for(int i = 0; i < m; i++) nums1_copy[i] = nums1[i];
        int pos_1 = 0, pos_2 = 0;
        for(int i = 0; i < m + n; i++){
            if(pos_2 < n && pos_1 < m){
                if(nums1_copy[pos_1] > nums2[pos_2]) nums1[i] = nums2[pos_2++];
                else nums1[i] = nums1_copy[pos_1++];
            }
            else if(pos_1 == m && pos_2 != n) nums1[i] = nums2[pos_2++];
            else if(pos_1 != m && pos_2 == n) nums1[i] = nums1_copy[pos_1++];
        }
    }
}