#include <stdio.h>
#include <stdlib.h>

int round_to_nearest_integer(double num) {
    return (int)(num + 0.5);
}

// Recursive binary search function to find the range for target
void binary_search(int* nums, int* answer_array, int left, int right, int* xuhao, int target, int numsSize) {
    if (left > right) {
        return;
    }

    int mid = left + (right - left) / 2;

    if (nums[mid] == target) {
        answer_array[*xuhao] = mid;
        (*xuhao)++;
        // Search for the leftmost occurrence
        int temp = mid;
        while (temp > 0 && nums[temp - 1] == target) {
            temp--;
            answer_array[*xuhao] = temp;
            (*xuhao)++;
        }

        // Search for the rightmost occurrence
        temp = mid;
        while (temp < numsSize - 1 && nums[temp + 1] == target) {
            temp++;
            answer_array[*xuhao] = temp;
            (*xuhao)++;
        }
        return;
    } else if (nums[mid] < target) {
        binary_search(nums, answer_array, mid + 1, right, xuhao, target, numsSize);
    } else {
        binary_search(nums, answer_array, left, mid - 1, xuhao, target, numsSize);
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* answer_array = (int*)malloc(numsSize * sizeof(int));
    int xuhao = 0;
    binary_search(nums, answer_array, 0, numsSize - 1, &xuhao, target, numsSize);

    if (xuhao == 0) {
        int* not_found = (int*)malloc(2 * sizeof(int));
        not_found[0] = -1;
        not_found[1] = -1;
        *returnSize = 2;
        return not_found;
    }

    int* result = (int*)malloc(2 * sizeof(int));
    result[0]=answer_array[0]; result[1]=answer_array[xuhao-1];

    *returnSize = 2;
    return result;
}

int main() {
    int nums[] = {5, 7, 7, 7,7,8, 8, 10};
    int numsSize = 6;
    int target = 8;
    int returnSize = 0;

    int* result = searchRange(nums, numsSize, target, &returnSize);

    printf("Result: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");
    system("pause");
    free(result);  // Free allocated memory

    return 0;
}
