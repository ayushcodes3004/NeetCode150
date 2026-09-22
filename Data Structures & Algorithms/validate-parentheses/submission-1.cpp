class Solution {
private:
    bool matches(char a, char b){
         return (a == '(' && b == ')') ||
               (a == '{' && b == '}') ||
               (a == '[' && b == ']');
    }
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            }else{
                if(st.empty()) return false;
                char r=st.top();
                st.pop();
                if(! matches(r,c)) return false;
            }
        }
        return st.empty();
    }
};
