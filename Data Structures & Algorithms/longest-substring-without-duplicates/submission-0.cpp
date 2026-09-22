class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if (n == 0) return 0;
        int maxi=1;
        unordered_set<char>st;
        int cnt=0;
        int i=0;
        int j=0;
        while(i<n && j<n){
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);

                maxi=max((int)st.size(),maxi);
                j++;
            }else{
                st.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};

