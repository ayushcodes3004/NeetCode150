class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        for(string s: strs){
            string temp=s;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(s);
        }
        for(auto [key,group]: mp){
            ans.push_back(group);
        }
        return ans;
    }
};
