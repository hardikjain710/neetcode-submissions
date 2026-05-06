class Solution {
public:
int cnt=0;
int solve(vector<int>& nums, int target,int i,int n,int sum){
    if(i==n && sum==target){
        cnt++;
        return cnt;
    }
    if(i==n && sum!=target){
        return 0;
    }
   return  solve(nums,target,i+1,n,sum+nums[i])+solve(nums,target,i+1,n,sum-nums[i]);

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        cnt=0;
       solve(nums,target,0,n,0);
       return cnt;
    }
};
