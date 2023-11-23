/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SUP 10000

struct pair{
    int first;  //存储count
    int second;  //存储key，即nums[i]
};

int comp(const void *a, const void *b) {
    struct pair *ha = (struct pair *)a;
    struct pair *hb = (struct pair *)b;     
    return hb->first - ha->first; 
} //降序

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int* ret = (int*) malloc(k * sizeof(int));
    *returnSize = k;
    struct pair* hashmap = (struct pair*) malloc((2*SUP+10)*sizeof(struct pair));
    memset(hashmap, 0, sizeof(hashmap));

    for(int i = 0; i < numsSize; i++){
        hashmap[nums[i] + SUP].first++;
        hashmap[nums[i] + SUP].second = nums[i];
    }

    qsort(hashmap, 2*SUP, sizeof(struct pair), comp);
    for(int i = 0; i < k; i++) ret[i] = hashmap[i].second;
    free(hashmap);
    return ret;

}