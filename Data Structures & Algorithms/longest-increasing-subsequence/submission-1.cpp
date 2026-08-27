class Solution {
public:

    int solve(int idx, vector<int>& nums, int n, int prev, vector<vector<int>>& dp){
        if(idx == n){
            return 0;
        }
        if(prev!=-1 && dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]){
            take = 1+solve(idx+1, nums, n, idx, dp);
        }
        int notTaken = solve(idx+1, nums, n , prev, dp);

        return dp[idx][prev+1]=max(take, notTaken);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, nums, n, -1, dp);
    }
};
