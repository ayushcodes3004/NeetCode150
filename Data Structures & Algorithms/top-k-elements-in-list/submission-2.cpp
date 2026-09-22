class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<pair<int,int>>arr;
        for(auto [f,s]: mp){
            arr.push_back({s,f});
        }
        sort(arr.begin(),arr.end());
        vector<int>ans;
        int n=arr.size();
        for(int i=n-1;i>=n-k;i--){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
