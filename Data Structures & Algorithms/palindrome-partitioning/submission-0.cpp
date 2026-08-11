class Solution {
public:

    bool isPalindrome(string s, int idx, int i){
        int start = idx;
        int end = i;
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    void doPartition(int idx, string s, vector<vector<string>>& ans, vector<string>& ds){
        if(idx == s.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s,idx,i)){
                ds.push_back(s.substr(idx, i-idx+1));
                doPartition(i+1, s, ans, ds);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
       vector<vector<string>> ans;
       vector<string> ds;
       doPartition(0,s,ans,ds);
       return ans; 
    }
};
