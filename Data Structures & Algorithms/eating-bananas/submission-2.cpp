class Solution {
private:
    bool isPossible(vector<int>& piles,int speed, int h){
        //ceil (a/b) = (a+b-1)/b
        long long total=0;
        for(auto p: piles){
            total+= (p+speed-1)/speed;
        }
        return (total<=h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxi=INT_MIN;
        for(auto it: piles){
            maxi=max(maxi,it);
        }
        int l=1;
        int r=maxi;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(piles,mid,h)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
