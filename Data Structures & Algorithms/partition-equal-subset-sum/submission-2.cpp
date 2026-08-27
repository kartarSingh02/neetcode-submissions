class Solution {
public:

    bool solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0) return nums[0]==target;
        if(dp[idx][target] !=-1) return dp[idx][target];
        //skip part
        int skip = solve(idx-1, target, nums, dp);
        //take part
        int take = 0;
        if(target >= nums[idx]){
            take = solve(idx-1, target-nums[idx], nums, dp);
        }
        return dp[idx][target] = skip | take;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        if(sum%2!=0) return false;
        else return solve(n-1, sum/2, nums, dp);
    }
};
