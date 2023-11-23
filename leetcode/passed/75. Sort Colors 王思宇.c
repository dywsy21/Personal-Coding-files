
void sortColors(int* nums, int numsSize) {
    int hashset[3];
    memset(hashset, 0, sizeof(hashset));
    for(int i = 0; i < numsSize; i++) hashset[nums[i]]++;
    int x = hashset[0] - 1, y = hashset[1] + x;
//0 ~ x, x + 1 ~ y, y + 1 ~ numsSize - 1
    for(int i = 0; i <= x; i++) nums[i] = 0;
    for(int i = x + 1; i <= y; i++) nums[i] = 1;
    for(int i = y + 1; i <= numsSize - 1; i++) nums[i] = 2;
}