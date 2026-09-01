class Solution {
public:

    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        int m = word1.length();
        int n = word2.length();
        if(j==n) return m-i; // deletion in word1 it means 
        if(i==m) return n-j; // inserting it means as word1 got finished 

        if(dp[i][j]!=-1) return dp[i][j];

        // if both are qual move to next iteration na
        if(word1[i] == word2[j]) return solve(i+1, j+1, word1, word2, dp);

        // either it is delete, insert, replace
        else return dp[i][j] = 1 + min({solve(i+1, j, word1, word2, dp), solve(i, j+1, word1, word2, dp), solve(i+1, j+1, word1, word2, dp)});
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
       return solve(0, 0, word1, word2, dp); 
    }
};
