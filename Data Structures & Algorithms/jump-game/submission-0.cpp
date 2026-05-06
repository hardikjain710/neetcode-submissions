class Solution {
public:
bool solve(vector<int>& nums,int n,int i){
    if(i>=n-1){
        return true;
    }

    for(int j=1; j<=nums[i]; j++){
       if(solve(nums,n,i+j)){
        return true;
       }
    }
    return false;
}
    bool canJump(vector<int>& nums) {
       
        int n=nums.size();
       return solve(nums,n,0);

       
        
    }
};
