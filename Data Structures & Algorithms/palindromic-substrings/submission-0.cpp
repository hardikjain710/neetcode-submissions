class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int len=1; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j=i+len-1;
                if(i==j){
                    dp[i][j]=true;
                }
                else if(j==i+1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }
                else{
                    dp[i][j]=dp[i+1][j-1] && s[i]==s[j];
                }
                if(dp[i][j]==true){
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};
