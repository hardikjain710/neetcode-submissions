class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int farthest=0,end=0;
        if(nums[0]==0){
            return 0;
        }

        int jump=0;
        for(int i=0; i<n-1; i++){
            farthest=max(nums[i]+i,farthest);
            if(i==end){
                jump++;
                end=farthest;
            }
           
        }
       
        return jump;

    }
};
