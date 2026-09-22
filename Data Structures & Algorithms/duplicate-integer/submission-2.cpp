class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // unordered_map<int,int>freq;
        // for(int num:nums){
        //     freq[num]++;
        //     if(freq[num]>=2) return true;
        // }
        // return false;
        set<int>s;
        for(int num:nums){
            if(s.find(num)==s.end()){
                s.insert(num);
            }else{
                return true;
            }
        }
        return false;
    }
};