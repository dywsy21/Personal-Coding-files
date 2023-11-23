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

int comp(const void* a,const void* b){
    if (*(int*)a <= *(int*)b)  return -1;
    else return 1;
}

int thirdMax(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int new_numsSize = removeDuplicates(nums, numsSize);
    if(new_numsSize < 3) return nums[new_numsSize - 1];
    else return nums[new_numsSize - 3];
}
