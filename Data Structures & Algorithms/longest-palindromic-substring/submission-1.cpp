class Solution {
public:

    bool isPalin(int i, int j, string& s, vector<vector<int>>& check){
        if(i>=j){
            return 1;
        }

        if(check[i][j] != -1){
            return check[i][j];
        }

        if(s[i] == s[j]){
            return check[i][j] = isPalin(i+1, j-1, s, check);
        }
        else return 0;
    }

    string longestPalindrome(string s) {
        int maxLen = INT_MIN;
        int sp = 0; //starting point
        int n = s.length();
        vector<vector<int>> check(n+1, vector<int>(n+1, -1)); 
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if (isPalin(i, j, s, check)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};
