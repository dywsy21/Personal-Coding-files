int ceiling(int num){
    int temp=num/3;
    if(temp*3==num) return temp;
    else return temp+1;
}

int max(int* nums, int numsSize, int* numindex){
    int maxnum=nums[0];
    *numindex=0;
    for(int i=1; i<numsSize; i++){
        if(nums[i]>maxnum) {
            maxnum=nums[i];
            *numindex=i;
        }
    }
    return maxnum;
}

long long maxKelements(int* nums, int numsSize, int k){
    long long ret=0;
    int numindex;
    for(int i=0; i<k; i++){
        ret+=max(nums, numsSize, &numindex);
        nums[numindex]=ceiling(nums[numindex]);
    }
    return ret;
}