class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> sufMax(n);

        sufMax[n-1] = height[n-1];

        for(int i = n-2 ; i>= 0; i--){
            sufMax[i] = max(sufMax[i+1], height[i]);
        }

        int total = 0;
        int maxLeft = height[0];

        for(int i = 0 ; i<n ;i++){

            maxLeft = max(maxLeft, height[i]);

            if(height[i] < maxLeft && height[i] < sufMax[i]){
                total+=min(maxLeft, sufMax[i]) - height[i];
            }
        }
        return total;
       
    }
};
