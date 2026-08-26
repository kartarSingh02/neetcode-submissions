class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefixMax = 1;
        int sufixMax = 1;
        int product = INT_MIN;

        for(int i = 0; i < n; i++){
            if(sufixMax == 0) sufixMax = 1;
            if(prefixMax == 0) prefixMax = 1;

            prefixMax*= nums[i];
            sufixMax*=nums[n-i-1];
            product = max(product, max(prefixMax, sufixMax));
        }
        return product;
    }
};
