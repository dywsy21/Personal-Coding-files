void insert(int* nums, int numsSize, int place, int newnum, int* dest_array) {
    if (place < 0 || place > numsSize) {
        return;
    }
    for (int i = 0; i < place; i++) {
        dest_array[i] = nums[i];
    }
    dest_array[place] = newnum;
    for (int i = place + 1; i < numsSize + 1; i++) {
        dest_array[i] = nums[i - 1];
    }
}

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int totalPerms = factorial(numsSize);
    *returnSize = totalPerms;

    int** ret = (int**)malloc(totalPerms * sizeof(int*));
    for (int i = 0; i < totalPerms; i++) 
        ret[i] = (int*)malloc(numsSize * sizeof(int));
    
    *returnColumnSizes = (int*)malloc(totalPerms * sizeof(int));
    for (int i = 0; i < totalPerms; i++) 
        (*returnColumnSizes)[i] = numsSize;

    if (numsSize == 1) {
        ret[0][0] = nums[0];
        return ret;
    }

    int* returnSize2;
    int** returnColumnSizes2;
    int** raw_nums = permute(nums, numsSize - 1, &returnSize2, &returnColumnSizes2);
    int raw_nums_size = factorial(numsSize - 1);

    int index = 0;
    for (int i = 0; i < raw_nums_size; i++) {
        for (int j = 0; j < numsSize; j++) {
            ret[index] = (int*)malloc(numsSize * sizeof(int));
            insert(raw_nums[i], numsSize - 1, j, nums[numsSize - 1], ret[index++]);
        }
        free(raw_nums[i]);
    }
    free(raw_nums);

    return ret;
}