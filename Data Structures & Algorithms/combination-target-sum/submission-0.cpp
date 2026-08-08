class Solution {
public:

    void findCombination(int index, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& ds){
        // when reaches end 
        if(index == nums.size()){
            //at that time if it becomes null
            if(target == 0) {
                // simply push the ds used into ans
                ans.push_back(ds);
            }
            return;
        }

        //to pick element only if curr ind element is less that target
        if(nums[index] <= target){
            ds.push_back(nums[index]);
            findCombination(index, nums, target-nums[index], ans, ds);
            // emtpy na if have to return to next iteration so it wont get carried in not pick case
            ds.pop_back();
        }

        // when not picked the element
        findCombination(index+1, nums, target, ans, ds);


    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, nums, target, ans, ds);
        return ans;
    }
};
