class Solution {
public:

    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){

    if (j == t.length())
        return 1;

    if (i == s.length())
        return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if (s[i] == t[j]) {

        int take = solve(i + 1, j + 1, s, t, dp);
        int skip = solve(i + 1, j, s, t, dp);

        return dp[i][j] = take + skip;
    }

    return dp[i][j] = solve(i + 1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(0,0,s,t,dp);
    }
};
