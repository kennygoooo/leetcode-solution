// 238. Product of Array Except Self 
vector<int> productExceptSelf(vector<int>& nums) { 

    int n = nums.size(); 

    vector<int> ans(n, 1); 

    for (int i = 1; i < n; ++i) ans[i] = ans[i - 1] * nums[i - 1]; 

    int suffix = 1; 

    for (int i = n - 1; i >= 0; --i) { 

        ans[i] *= suffix; 

        suffix *= nums[i]; 

    } 

    return ans; 

} 

 

// vector<int>& nums 

// Why use &?  

// Avoid copying 

// If you write vector<int> nums, when calling the function the entire vector (all its elements) will be copied into the parameter. This is inefficient, especially when the vector is large. By adding & (reference), it means "directly refer to the original vector," so no extra copy is made. This improves both speed and memory usage. 

// Allow modification 

// If the function signature is vector<int>& nums, then any modifications to nums inside the function will also affect the original vector outside the function. 


// vector<int> ans(n, 1); 

// vector<int> ans(5, 1); 
// Result => ans = {1, 1, 1, 1, 1}