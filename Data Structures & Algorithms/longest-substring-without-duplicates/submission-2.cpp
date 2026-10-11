class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        int i=0;
        int j=0;
        vector<int>freq(256,0);
        while(j<n){
            while(freq[s[j]]){
                freq[s[i]]--;
                i++;
            }
            freq[s[j]]++;
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
