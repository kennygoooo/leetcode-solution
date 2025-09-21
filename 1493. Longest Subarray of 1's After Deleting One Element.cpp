// 1493. Longest Subarray of 1's After Deleting One Element
// Sliding Window
// Use two pointers to do sliding window

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int left = 0, maxLength = 0, zeroCount = 0;

        for (int right = 0; right < nums.size(); right++){
            if (nums[right] == 0){
                zeroCount++;
            }
            while (zeroCount > 1){
                if (nums[left] == 0){
                    zeroCount--;
                }
                left++;
            }
            maxLength = max(maxLength, right - left);

            if (right == nums.size()-1 && zeroCount == 0){
                maxLength= right;
            }
        }
        return maxLength;
    }
};