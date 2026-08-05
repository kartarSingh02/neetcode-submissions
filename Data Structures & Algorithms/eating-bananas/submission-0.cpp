class Solution {
public:
    long long calTime(vector<int> piles, int rate){
        int totalTime = 0;
        for(int i : piles){
            totalTime += ceil((double)i/rate);
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long time = calTime(piles, mid);
            if (time <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
