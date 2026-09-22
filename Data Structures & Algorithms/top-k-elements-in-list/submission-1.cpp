class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto num: nums){
            freq[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // priority_queue<pair<int,int>>pq;
        for(auto [n,c] : freq){
            pq.push({c,n});
        }
        while(pq.size()!=k){
            pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            auto rem=pq.top();
            pq.pop();
            ans.push_back(rem.second);
        }
        return ans;
    }
};
