class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>>distTime(speed.size());
        for(int i = 0; i < position.size(); i++){
            distTime[i] = {target - position[i], ((target - position[i]) / (1.0 * speed[i]))};
        }
        sort(distTime.begin(), distTime.end());
        int res = 1;
        for(int i = 1; i < distTime.size(); i++){
            if(distTime[i - 1].second >= distTime[i].second){
                distTime[i].second = distTime[i - 1].second;
            }else{
                res++;
            }
        }
        return res;
    }
};