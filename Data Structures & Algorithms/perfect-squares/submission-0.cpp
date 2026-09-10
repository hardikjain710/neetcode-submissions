class Solution {
   public:
    int numSquares(int n) {
        int x = sqrt(n);
        if (x * x == n) {
            return 1;
        }
        vector<int> dp(n + 1, n);
        dp[0]=0;
        for (int i = 1; i <= n; i++) {
            int j = 1;
            while (i >= j * j) {
            dp[i] = min(dp[i],1 + dp[i - (j * j)]);
                j++;
            }
        
     
        }
        return dp[n];
    }
};