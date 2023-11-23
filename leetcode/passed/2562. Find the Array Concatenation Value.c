//itoa不一定能用
long long findTheArrayConcVal(int* nums, int numsSize){
    char buffer1[50],buffer2[50];
    int L=0,R=numsSize-1,temp;
    long long ret=0;
    while(L<R){
        itoa(nums[L],buffer1,10);
        itoa(nums[R],buffer2,10);
        strcat(buffer1,buffer2);
        temp=atoi(buffer1);
        ret+=temp;
        L++; R--;
    }
    if(L==R) ret+=nums[L];

    return ret;
}

//使用sprintf
long long findTheArrayConcVal(int* nums, int numsSize){
    char buffer1[50],buffer2[50];
    int L=0,R=numsSize-1,temp;
    long long ret=0;
    while(L<R){
        sprintf(buffer1,"%d",nums[L]);
        sprintf(buffer2,"%d",nums[R]);
        strcat(buffer1,buffer2);
        temp=atoi(buffer1);
        ret+=temp;
        L++; R--;
    }
    if(L==R) ret+=nums[L];

    return ret;
}

//sprintf(str, "%d%d", nums[i], nums[j]); 这样就行，不用strcat