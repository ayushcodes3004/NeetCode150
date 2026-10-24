class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int>freq(26,0);
        vector<int>freq2(26,0);
        for(auto it: s1){
            freq[it-'a']++;
        }
        int len=s1.size();
        int i=0;
        int j=0;
        while(j<len){
            freq2[s2[j]-'a']++;
            j++;
        }
        if(freq==freq2) return true;
        while(j<s2.size()){
            freq2[s2[i]-'a']--;
            i++;
            freq2[s2[j]-'a']++;
            j++;
            if(freq==freq2) return true;
        }
        return false;
    }
};
