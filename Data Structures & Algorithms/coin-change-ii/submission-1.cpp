class Solution {
public:

    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(i == coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        if(amount == 0) return dp[i][amount] = 1;
        int take = 0;
        if(coins[i] <= amount) take = solve(i, amount - coins[i], coins, dp);
        int noTake = solve(i+1, amount, coins, dp);
        return dp[i][amount] = take + noTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(0, amount, coins, dp);
    }
};
