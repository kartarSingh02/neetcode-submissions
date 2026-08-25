class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);

        // we know that to build amount 0 we need 0 coins
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {

            for (int coin : coins) {
                
                // if amount i - coin >= 0 as well as inside dp[i-coin] is MAX means we cant build amount (we are going sequentially)
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {

                    // either dp[i] or 1 + previous coin 
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};