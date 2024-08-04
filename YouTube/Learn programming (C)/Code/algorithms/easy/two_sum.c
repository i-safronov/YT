#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    if (numsSize <= 1) return nums; 
    int* new_arr = malloc(2 * sizeof(int)); 
    *returnSize = 2;

    for (int i = 0; i < numsSize; ++i) {
        for (int j = 0; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target && i != j) {
                new_arr[0] = i; 
                new_arr[1] = j; 
                return new_arr; 
            }
        }
    }

    return new_arr; 
}