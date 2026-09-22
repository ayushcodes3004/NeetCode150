class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow=prices[0];
        int maxi=0;
        for(int i=1;i<prices.size();i++){
            int curr=prices[i]-minTillNow;
            maxi=max(maxi,curr);
            minTillNow=min(minTillNow,prices[i]);
        }
        return maxi;
    }
};
