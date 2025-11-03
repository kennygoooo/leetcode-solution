// 338. Counting Bits

// dp

int* countBits(int n, int* returnSize) {
    *returnSize = n+1;
    int* dp = malloc((*returnSize) * sizeof(int));
    dp[0] = 0;

    for (int i = 0; i <= n; i++){
        dp[i] = dp[i>>1] + (i & 1);
    }
    return dp;
}