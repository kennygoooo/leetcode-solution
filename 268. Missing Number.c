// 268. Missing Number


int missingNumber(int* nums, int numsSize) {
    
    int xorSum = 0;

    for (int i = 0; i <= numsSize; i++){
        xorSum ^= i;
    }

    for (int i = 0; i < numsSize; i++){
        xorSum ^= nums[i];
    }
    return xorSum;    
}