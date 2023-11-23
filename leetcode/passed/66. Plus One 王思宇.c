

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
//先处理全是9的特殊情况

    int det=1;
    for(int i=0;i<=digitsSize-1;i++){
        if(digits[i]!=9){
            det=0;
            break;
        }
    }

    if(det){
        (*returnSize)=digitsSize+1;   
        int* ret=(int*) malloc((digitsSize+1)*sizeof(int));
        for(int p=digitsSize;p>=1;p--) ret[p]=0;
        ret[0]=1;
        return ret;
    }

//一般情况如下
    (*returnSize)=digitsSize;
    int* ret= (int*) malloc((digitsSize)*sizeof(int));
    for(int i=digitsSize-1;i>=0;i--) ret[i]=digits[i];
    ret[digitsSize-1]++;
    for(int j=digitsSize-1;j>=0;j--){
        if(ret[j]>=10 && j>0){
            ret[j]-=10;
            ret[j-1]++;
        }

    }
    return ret;


}