class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0; 
        for(int i=0; i<n; i++){
            sum+=stones[i];
        }
        int target=sum/2;
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));

        for(int j=1; j<=target; j++){
            if(stones[0]<=j){
                dp[0][j]=stones[0];
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
               dp[i][j] = dp[i-1][j];
                if(j>=stones[i]){
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-stones[i]]+stones[i]);
                }

            }
        }
        int max_weight = dp[n-1][target];
         return sum - 2 * max_weight;;


    }
};