class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ans(256,-1);
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;
        while(r < n){
            if(ans[s[r]] != -1 && ans[s[r]] >= l ){ // this means ele exist in list
                l = ans[s[r]] + 1;
            }
            ans[s[r]] = r;
            int length = r-l+1;
            maxLen = max(maxLen,length);
            r++;
        }
        return maxLen;  
    }
};
