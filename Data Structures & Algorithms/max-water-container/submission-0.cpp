class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int low = 0;
        int high = n-1;
        int ans=0;

        while(low < high){
            ans = max(ans , min(heights[low], heights[high]) * (high-low));

            if(heights[low] < heights[high]) low++;
            else high--;
        }
        return ans;
    }
};
