class Solution {
public:
// bool solve(vector<int>& nums,int n,int i){
//     if(i>=n-1){
//         return true;
//     }

//     for(int j=1; j<=nums[i]; j++){
//        if(solve(nums,n,i+j)){
//         return true;
//        }
//     }
//     return false;
// }
    bool canJump(vector<int>& nums) {
       
        int n=nums.size();
        int maxReach=0;
        for(int i=0; i<n; i++){
            if(i>maxReach){
                return false;
            }
            maxReach=max(i+nums[i],maxReach);
            if(maxReach>=n-1){
                return true;
            }
        }
        return false;
         
    }
};

