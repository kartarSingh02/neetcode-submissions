class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefMax(n);
        vector<int> sufMax(n);

        prefMax[0] = height[0];
        sufMax[n-1] = height[n-1];

        for(int i = 1; i<n ;i++){
            prefMax[i] = max(prefMax[i-1], height[i]);
        }

        for(int i = n-2 ; i>= 0; i--){
            sufMax[i] = max(sufMax[i+1], height[i]);
        }

        int total = 0;

        for(int i = 0 ; i<n ;i++){
            if(height[i] < prefMax[i] && height[i] < sufMax[i]){
                total+=min(prefMax[i], sufMax[i]) - height[i];
            }
        }
        return total;
       
    }
};
