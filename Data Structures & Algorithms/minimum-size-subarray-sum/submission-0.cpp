class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int sum=0;
        int len=INT_MAX;
        while(r<n){
            sum+=nums[r];
            if(sum>=target){
                while(l<n && sum>=target){
                len=min(r-l+1,len);
                    sum-=nums[l];
                    l++;
                }
            }
         
            r++;
        }
        if(len==INT_MAX){
            return 0;
        }
        return len;
    }
};