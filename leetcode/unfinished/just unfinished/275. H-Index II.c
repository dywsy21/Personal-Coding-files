#define min(a,b) ((a)<=(b)?(a):(b))

int hIndex(int* citations, int citationsSize){  //citationsSize-i为>=citation[i]的论文数
    int L=0,R=citationsSize,mid;
    while(L<=R){
        mid=(L+R)/2;
        if(mid>=citationsSize) break;
        if(citations[mid]<citationsSize-mid) L=mid+1;
        if(citations[mid]>citationsSize-mid) R=mid-1;
        if(citations[mid]==citationsSize-mid) return citations[mid];
    }
    if(L<R) return min(citations[R],citationsSize-R);

    if(L<citationsSize)
        return min(citations[L],citationsSize-L);
    else
        return citationsSize-L;

}