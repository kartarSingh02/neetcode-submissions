class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(auto it:nums) mp[it]++;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

        for(auto it:mp){
            pq.push({it.second, it.first}); // frequency, number(key)
            if(pq.size() > k) pq.pop(); // as its min heap - min at top always
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
