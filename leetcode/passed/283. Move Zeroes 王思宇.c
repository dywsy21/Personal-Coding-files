void moveZeroes(int* nums, int numsSize){
    int zero_count=0,index=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==0) zero_count++;
    }

    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[index]=nums[i];
            index++;
        }
    }
    
    for(int i=numsSize-1;i>=numsSize-zero_count;i--) nums[i]=0;
}