class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int toFind=target-nums[i];
            if(mp.find(toFind)!=mp.end())   return {mp[toFind],i};
            mp[nums[i]]=i;
        }
        return {};
    }
};
