class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        int i = 1;
        vector<vector<int>> result;
        vector<int> cur_interval(intervals[0]);
        while (i < n) {
            if (intervals[i][0] <= cur_interval[1]) {
                cur_interval[0] = min(cur_interval[0], intervals[i][0]);
                cur_interval[1] = max(cur_interval[1], intervals[i][1]);
            } else {
                result.push_back(cur_interval);
                cur_interval = intervals[i];
            }
            ++i;
        }

        result.push_back(cur_interval);

        return result;
    }

};