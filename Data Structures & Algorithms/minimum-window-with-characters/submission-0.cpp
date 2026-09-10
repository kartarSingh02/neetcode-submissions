class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int hash[256] = {0};

        int minLen = INT_MAX;
        int startIndex = -1;

        int l = 0;
        int r = 0;
        int count = 0;

        for(int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while(r < n) {

            // include s[r] in the window
            if(hash[s[r]] > 0) {
                count++;
            }

            hash[s[r]]--;

            // valid window
            while(count == m) {

                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }

                // remove s[l] from window
                hash[s[l]]++;

                // now this character becomes required again
                if(hash[s[l]] > 0) {
                    count--;
                }

                l++;
            }

            r++;
        }

        return startIndex == -1
            ? ""
            : s.substr(startIndex, minLen);
    }
};