class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n=nums.size();
        int p=1,s=1;
        int ans=nums[0];


        for(int i=0; i<n; i++){
            p=nums[i]*p;
            s=nums[n-i-1]*s;
            ans=max({p,s,ans});

            if(p==0){
                p=1;
            }
            if(s==0){
                s=1;
            }

        }
        return ans;
    }
};
// 1 ,  2, -6. -24
//-24,-24,-12, 4