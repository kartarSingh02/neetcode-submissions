class Solution {
public:

    int solve(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp){
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        if(i==m && j==n && i+j==N) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        if(i+j>=N) return 0;

        int result = 0;
        if(s1[i]==s3[i+j]) result = solve(i+1, j, s1, s2, s3, dp);
        if(s2[j]==s3[i+j]) result = solve(i, j+1, s1, s2, s3, dp);
        
        return dp[i][j] = result;

    }

    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};
