class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int prev){
        int m = matrix.size();
        int n = matrix[0].size();

        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j] <= prev) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = 1 + max({solve(i-1, j, matrix, dp, matrix[i][j]), solve(i, j+1, matrix, dp, matrix[i][j]), solve(i+1, j, matrix, dp, matrix[i][j]), solve(i, j-1, matrix, dp, matrix[i][j])});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxPath = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxPath = max(maxPath, solve(i, j, matrix, dp, -1));
            }
        }
        return maxPath;
    }
};
