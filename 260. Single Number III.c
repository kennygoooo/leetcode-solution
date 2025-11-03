// 260. Single Number III

// Bit
// xor

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int x = 0;
    for (int i = 0; i < numsSize; i++){
        x ^= nums[i];
    }

    unsigned int diff = ((unsigned int)x) & (-(unsigned int)x);
    int a = 0 , b = 0;
    
    for (int i = 0; i < numsSize; i++){

        if (nums[i] & diff) {
            a ^= nums[i];
        } else {
            b ^= nums[i];
        }
    }

    int* ans = malloc(2 * sizeof(int));
    ans[0] = a;
    ans[1] = b;
    
    *returnSize = 2;
    return ans;
}