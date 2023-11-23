int ceiling(int num){
    int temp=num/3;
    if(temp*3==num) return temp;
    else return temp+1;
}
int comp(const void* a,const void* b){
    return *(int*)b - *(int*)a;
}

void max(int* nums, int begin, int end, int* maxnum, int* maxnum_index,long long* ret){
    *maxnum=nums[begin];
    *maxnum_index=begin;
    for(int i=begin+1; i<=end; i++)
        if (nums[i]>*maxnum) {
            *maxnum=nums[i];
            *maxnum_index=i;
        }
    *ret+=nums[*maxnum_index];
    nums[*maxnum_index]=ceiling(nums[*maxnum_index]);
}




long long maxKelements(int* nums, int numsSize, int k){
    long long ret=0;
    int numindex;
    qsort(nums, numsSize, sizeof(int), comp);
    int maxnum,maxnum_index,max_comp=0; 
    for(int i=0; i<k; i++){
        max(nums,0,max_comp,&maxnum,&maxnum_index,&ret);
        if(max_comp+1<numsSize && nums[maxnum_index]<nums[max_comp+1]) max_comp++;
    }
    return ret;
}
