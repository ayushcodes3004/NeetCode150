class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(), wordList.end());
        if(!s.contains(endWord)) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string get=q.front().first;
            int step=q.front().second;
            q.pop();
            if(get==endWord)    return step;
            int n=get.size();
            for(int i=0;i<n;i++){
                string temp=get;
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(s.contains(temp)){
                        q.push({temp,step+1});
                        s.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
