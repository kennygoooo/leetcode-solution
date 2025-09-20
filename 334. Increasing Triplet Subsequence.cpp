// 334. Increasing Triplet Subsequence 
bool increasingTriplet(vector<int>& nums) { 

        int first = INT_MAX, second = INT_MAX; 

        int n = nums.size(); 

  

        for (int i = 0; i < n; i++) { 

            int x = nums[i]; 

            if (x <= first) { 

                first = x;  // new smallest value 

            } else if (x <= second) { 

                second = x; // new second smallest value 

            } else { 

                return true; // found first < second < x 

            } 

        }  

        return false; 

    } 