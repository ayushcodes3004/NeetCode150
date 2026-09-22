class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(string st: strs){
            s+=st;
            s+='.';
        }
        return s;
    }

    vector<string> decode(string s) {
        // string token;
        // stringstream ss(s);
        // vector<string>strs;
        // while (getline(ss, token, '.')) {
        //     strs.push_back(token);
        // }
        // return strs;
        vector<string>ans;
        int idx=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                ans.push_back(s.substr(idx,i-idx));
                idx=i+1;
            }
        }
        return ans;
    }
};
