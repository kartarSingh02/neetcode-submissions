class Solution {
public:

    void findPermutation(
        vector<int>& nums,
        vector<vector<int>>& ans,
        vector<int>& ds,
        vector<bool>& used
    ) {
        // We have used all elements
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        // Try every unused element
        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // Pick
            used[i] = true;
            ds.push_back(nums[i]);

            findPermutation(nums, ans, ds, used);

            // Backtrack
            ds.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> used(nums.size(), false);

        findPermutation(nums, ans, ds, used);

        return ans;
    }
};