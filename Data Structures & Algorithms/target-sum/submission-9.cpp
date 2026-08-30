class Solution {
public:

    int solve(int idx, vector<int>& nums, int target, int n,
              vector<vector<int>>& dp, int offset) {

        if (idx == n)
            return target == 0;

        if (target < -offset || target > offset)
            return 0;

        if (dp[idx][target + offset] != -1)
            return dp[idx][target + offset];

        return dp[idx][target + offset] =
            solve(idx + 1, nums, target - nums[idx], n, dp, offset)
            +
            solve(idx + 1, nums, target + nums[idx], n, dp, offset);
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums)
            sum += x;

        // Target is impossible
        if (target > sum || target < -sum)
            return 0;

        vector<vector<int>> dp(
            n,
            vector<int>(2 * sum + 1, -1)
        );

        return solve(0, nums, target, n, dp, sum);
    }
};