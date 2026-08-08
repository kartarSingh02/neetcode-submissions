class Solution {
public:

    void findCombination(int index, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& ds){
        if(target == 0) {
            ans.push_back(ds);
            return;
        }

        for(int i = index; i<nums.size(); i++){
            if(i>index && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;

            ds.push_back(nums[i]);
            findCombination(i+1, nums, target-nums[i], ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombination(0, candidates, target, ans, ds);
        return ans;
    }
};
