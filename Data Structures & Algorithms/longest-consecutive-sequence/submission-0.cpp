class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(int i:nums){
            if(st.find(i-1) == st.end()){
                int curr = i;
                int currStreak = 1;

                while(st.find(curr + 1) != st.end()){
                    curr++;
                    currStreak++;
                }

                ans = max(ans, currStreak);
            }
        }
        return ans;
    }
};
