class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));

        for (int i = 0; i <= target; i++) {
            dp[0][i] = 0;
        }
        for (int j = 0; j <= n; j++) {
            dp[j][0] = 1;
        }

        for (int j = 1; j <= target; j++) {
            for (int i = 1; i <= n; i++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[n][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};