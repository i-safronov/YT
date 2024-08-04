#include <stdio.h>
#include <stdlib.h>

/*
1 - change duplicate to -1 and count of unique elements* 
2 - sort from n .. -1 
3 - return 
*/

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0; 

    int idx = 1; 

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[idx] = nums[i]; 
            ++idx; 
        }
    }

    return idx; 
}