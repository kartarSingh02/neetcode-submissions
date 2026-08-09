class Solution {
public:

    void findSubset(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        findSubset(idx+1, nums, ans, ds);

        ds.pop_back();

        while(idx+1 < nums.size() && nums[idx]==nums[idx+1]) idx+=1;
        findSubset(idx+1, nums, ans, ds);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubset(0, nums, ans, ds);
        return ans;
    }
};
