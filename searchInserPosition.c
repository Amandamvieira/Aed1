#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int head = 0;
    int end = numsSize;
    
    while (1) {
        int now = (head + end) / 2;
        
        if (nums[now] > target) {
            if (now == 0 || nums[now - 1] < target) {
                return now;
            } else if (nums[now - 1] > target) {
                end = now;
            } else {
                return now - 1;
            }
        } else if (nums[now] < target) {
            if (now + 1 == numsSize || nums[now + 1] >= target) {
                return now + 1;
            } else {
                head = now;
            }
        } else {
            return now;
        }
    }
    
    return -1;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = searchInsert(nums, numsSize, target);
    
    printf("Result: %d\n", result);
    
    return 0;
}