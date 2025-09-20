//1679. Max Number of K-Sum Pairs 
int maxOperations(vector<int>& nums, int k) { 

        unordered_map<int, int> freq; 

        int operations = 0; 

        for (int x : nums){ 

            int target = k - x; 

            if (freq[target] > 0){ 

                freq[target]--; 

                operations++; 

            } else { 

                freq[x]++; 

            } 

        } 

        return operations; 

    } 

// Learning
// for ( int x : nums)
// equal to =>
// for (int i = 0; i < nums.size(); i++) {
//    int x = nums[i];
// }

//Method 2
int maxOperations(vector<int>& nums, int k) { 
    int left = 0;
    int right = nums.size() - 1;
    int count = 0;

    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum == k) {
        left++;
        rigt--;
        count++;
      } else if (sum > k) {
        right--;
      } else {
        left++;
      }
    }
}
    