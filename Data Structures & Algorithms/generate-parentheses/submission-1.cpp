class Solution {
public:

    void genParan(vector<string>& ans, int n, int open, int close, string currString){
        if(currString.size() == n*2){
            ans.push_back(currString);
            return;
        }

        if(open<n) genParan(ans, n, open+1, close, currString + '(');
        if(close<open) genParan(ans, n, open, close+1, currString + ')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // open, close and emptry string
        genParan(ans, n, 0, 0, "");
        return ans;
    }
};
