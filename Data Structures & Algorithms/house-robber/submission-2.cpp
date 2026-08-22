class Solution {
public:

    int findMaxSum(int idx, vector<int>& nums, vector<int>& dp){
        dp[0] = nums[0];
        for(int i = 1;i<=idx;i++){
            dp[i] = max(nums[i] + (i>1 ? dp[i-2] : 0) , 0 + dp[i-1]);
        }
        return dp[idx];
    }

    int rob(vector<int>& nums) {
        int idx = nums.size()-1;
        vector<int> dp(idx+1, 0);
        return findMaxSum(idx, nums, dp);;
    }
};
