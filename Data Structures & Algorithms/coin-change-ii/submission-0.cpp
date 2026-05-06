class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=1; i<=n; i++){
            dp[i][0]=1;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                int d=j-coins[i-1];
                if(d>=0){
                    dp[i][j]=dp[i-1][j]+dp[i][d];
                }
                else{
                    dp[i][j]=dp[i-1][j];

                }
                
            }
        }
        return dp[n][amount];
    }
};
