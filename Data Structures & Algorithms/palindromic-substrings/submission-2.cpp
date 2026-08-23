class Solution {
public:

    bool isPalin(int i, int j, string& s, vector<vector<int>>& dp){
        if(i>=j) return true;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j] = isPalin(i+1, j-1, s, dp);
        }
        return dp[i][j] = false;
    }

    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalin(i, j, s, dp)){
                    count++;
                }
            }
        }
        return count;
    }
};
