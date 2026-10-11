class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minTillNow=prices[0];
        int maxi=0;
        for(int i=1;i<n;i++){
            int p=prices[i];
            minTillNow=min(p,minTillNow);
            int profit=p-minTillNow;
            maxi=max(maxi,profit);
        }
        return maxi;
    }
};
