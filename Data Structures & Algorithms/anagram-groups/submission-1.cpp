class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        vector<vector<string>>ans;
        for(string s: strs){
            vector<int>freq(26,0);
            for(auto c:s)   freq[c-'a']++;
            mp[freq].push_back(s);
        }
        for(auto [key,group]: mp){
            ans.push_back(group);
        }
        return ans;
    }
};
