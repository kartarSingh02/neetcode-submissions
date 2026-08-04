class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];

        int index = 0;
        while(index < s1.size()){
            if(s1.at(index) == s2.at(index)){
                index++;
            }
            else break;
        }
        return index == 0 ? "" : s1.substr(0,index);

    }
};