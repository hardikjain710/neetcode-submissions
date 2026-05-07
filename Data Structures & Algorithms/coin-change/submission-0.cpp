class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<long long>>dp(n+1,vector<long long>(amount+1,0));

        for(int i=0; i<=amount; i++){
            dp[0][i]=INT_MAX;
        }



        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                int d=j-coins[i-1];
                if(d>=0){
                    dp[i][j]=min(1+dp[i][d],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }

            }
        }
        if(dp[n][amount]==INT_MAX){
            return -1;
        }
        return dp[n][amount];
        
    }
};
