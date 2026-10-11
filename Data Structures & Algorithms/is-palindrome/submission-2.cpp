class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if((s[i]>='a' && s[i]<='z' )|| (s[i]>='A' && s[i]<='Z' )||(s[i]>='0' && s[i]<='9' )){
                char c=tolower(s[i]);
                temp+=c;
            }  
        }

        int i=0;
        int j=temp.size()-1;
        while(i<=j){
            if(temp[i]!=temp[j])    return false;
            i++;
            j--;
        }
        return true;
    }
};
