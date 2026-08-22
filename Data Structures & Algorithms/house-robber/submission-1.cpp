class Solution {
public:

    int findMaxSum(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        dp[idx] = max(nums[idx] + findMaxSum(idx-2, nums, dp), 0 + findMaxSum(idx-1, nums, dp));
        return dp[idx];
    }

    int rob(vector<int>& nums) {
        int idx = nums.size()-1;
        vector<int> dp(idx+1, -1);
        return findMaxSum(idx, nums, dp);;
    }
};
