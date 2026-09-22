class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int>s;
        for(int num: nums){
            s.insert(num);
        }
        int maxi=0;
        for(int num: nums){
            if(!s.count(num-1)){
                int cnt=1;
                int n=num;
                while(s.count(n+1)){
                    cnt++;
                    n++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};
