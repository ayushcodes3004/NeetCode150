class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=0;
        int i=0;
        int j=heights.size()-1;
        while(i<j){
            int len=(j-i);
            int curr=len * min(heights[i],heights[j]);
            maxi=max(curr,maxi);
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};
