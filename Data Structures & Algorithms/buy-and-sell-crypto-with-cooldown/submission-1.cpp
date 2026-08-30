class Solution {
public:

    int solve(int i, vector<int>& prices, int n, bool toBuy, vector<vector<int>>& dp){
        if(i>=n) return 0;
        int profit = 0;

        if(dp[i][toBuy] != -1) return dp[i][toBuy];

        if(toBuy){
        // it means if i have already bought it today then we need to sell first
            int take = solve(i+1, prices, n, 0, dp) - prices[i];
            // if not bought then we can call buy function only as not sold
            int noTake = solve(i+1, prices, n, 1, dp);

            profit = max(profit, max(take, noTake));
        }
        else{
            // we have sold then we can buy after cool down
            int sell = prices[i] + solve(i+2, prices, n, 1, dp);
            // havent sold yet
            int noSell = solve(i+1, prices, n, 0, dp);

            profit = max(profit, max(sell, noSell));
        }

        return dp[i][toBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        // sent true coz inutsaly we need to buy only na
        return solve(0, prices, n, 1, dp);
    }
};
