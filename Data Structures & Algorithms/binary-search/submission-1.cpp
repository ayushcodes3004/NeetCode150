class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        sort(nums.begin(),nums.end());
        while(i<=j){
            int mid= i+(j-i)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                j--;
            }else{
                i++;
            }
        }
        return -1;
    }
};
