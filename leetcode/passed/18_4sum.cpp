/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<bits/stdc++.h>
#define MAXSIZE 1E5

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    int** answer_arrays = (int**)malloc(MAXSIZE * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAXSIZE * sizeof(int));
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), comp);

    int max_useful_sub = numsSize - 4;  // Updated this line

    for (int i = 0; i <= max_useful_sub; i++) {
        if (i > 0 && nums[i] == nums[i - 1])  // Skip duplicates
            continue;

        for (int j = i + 1; j <= max_useful_sub + 1; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])  // Skip duplicates
                continue;

            int k = j + 1;
            int p = numsSize - 1;

            while (k < p) {
                if ((long long)nums[i] + nums[j] + nums[k] + nums[p] == target) {
                    int* temp = (int*)malloc(4 * sizeof(int));
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    temp[3] = nums[p];

                    answer_arrays[*returnSize] = temp;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    k++;
                    p--;

                    while (k < p && nums[k] == nums[k - 1])
                        k++;

                    while (k < p && nums[p] == nums[p + 1])
                        p--;
                } else if ((long long)nums[i] + nums[j] + nums[k] + nums[p] < target) {
                    k++;
                } else {
                    p--;
                }
            }
        }
    }

    return answer_arrays;
}

int main() {
    int nums[] = {1, 0, -1, 0, -2, 2};
    int numsSize = 6;
    int target = 0;
    int returnSize;
    int* returnColumnSizes;

    int** result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory for the result and returnColumnSizes
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    system("pause");
    return 0;
}
