int removeDuplicates(int* nums, int numsSize){
    int i=1, ans=1;
    while(i < numsSize){
        if(nums[i] == nums[i-1]){
            for(int j=i; j<numsSize-1; j++)  nums[j] = nums[j+1];
            numsSize--;
        }
        else{
            i++;
            ans++;
        }
    }
    return ans;
}