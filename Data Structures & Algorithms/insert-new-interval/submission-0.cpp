class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{newInterval};

        for (auto inter : intervals) {
            // goes completely after
            if (res.back().back() < inter.front())
                res.push_back(inter);
            // goes completely before
            else if (inter.back() < res.back().front()) {
                res.push_back(inter);
                swap(res.back(), res[res.size()-2]);
            // merge
            } else {
                res.back().front() = min(res.back().front(), inter.front());
                res.back().back()  = max(res.back().back(),  inter.back());
            }
        }
        return res;
    }
};