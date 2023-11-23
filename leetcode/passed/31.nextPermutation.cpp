#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int* array, int starting_point, int array_len) {
    int left = starting_point, right = array_len - 1;
    while (left < right) {
        swap(&array[left], &array[right]);
        left++;
        right--; 
    }
}

void nextPermutation(int* nums, int numsSize) {
    int det=0;
    for (int i = numsSize - 1; i >= 1; i--){
        if (nums[i-1]>=nums[i]) det++;
    }
    if  (det==numsSize-1) {
        reverse(nums,0,numsSize);
        return;
    }

    for (int i = numsSize - 1; i >= 1; i--) {
        if (nums[i - 1] < nums[i]) {
            // Find the smallest element on the right side that is greater than nums[i-1]
            int j = i;
            while (j < numsSize && nums[j] > nums[i - 1]) {
                j++;
            }
            // Swap nums[i-1] and the smallest element found
            swap(&nums[i - 1], &nums[j - 1]);
            // Reverse the elements after nums[i-1]
            reverse(nums, i, numsSize);
            break;
        }
    }

}

int main() {
    int nums[5] = {1, 2, 3, 4, 5};
    int numssize = 5;
    nextPermutation(nums, numssize);
    for (int i = 0; i < numssize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
