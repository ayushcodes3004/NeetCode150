class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freq;
        int m=t.size();
        for(int i=0;i<m;i++){
            freq[t[i]]++;
        }

        int l=0;
        int r=0;
        int cnt=0;
        int minlen=INT_MAX;
        int sIdx=-1;

        while(r<s.size()){
            if(freq[s[r]]>0){
                cnt++;
            }    
            freq[s[r]]--;
            r++;

            while(cnt==m){
                if(r-l<minlen){
                    minlen=r-l;
                    sIdx=l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
        }
        return (sIdx == -1) ? "" : s.substr(sIdx, minlen);
    }
};
