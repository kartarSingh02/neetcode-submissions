class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // Monotonically non-increasing
        vector<int> ans;
        int left = 0, right = 0;
        while(right < k) {
            while(!dq.empty() && (nums[right] > dq.back())) {
                dq.pop_back();
            }
            dq.push_back(nums[right]);
            right++;
        }
        ans.push_back(dq.front());
        while(right < n) {
            while(!dq.empty() && (nums[right] > dq.back())) {
                dq.pop_back();
            }
            dq.push_back(nums[right]);
            if(nums[left] == dq.front()) {
                dq.pop_front();
            }
            left++;
            right++;
            ans.push_back(dq.front());
        }
        return ans;
    }
};