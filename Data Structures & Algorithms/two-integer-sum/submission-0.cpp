class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int fNum = nums[i];
            int diff = target - fNum;
            if(mp.find(diff)!=mp.end()){
                return {mp[diff],i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
