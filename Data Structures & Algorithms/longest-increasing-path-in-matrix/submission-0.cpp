int n,m;

int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
class Solution {
public:

int solve(vector<vector<int>>& matrix,int i,int j, vector<vector<int>>& dp){
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    dp[i][j]=1;
    for(int k=0; k<4; k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        if(ni>=0 && ni<n && nj>=0 && nj<m){
            int x=matrix[ni][nj];
            if(x>matrix[i][j]){
                dp[i][j]=max(dp[i][j],1+solve(matrix,ni,nj,dp));
            }
        }
    }
    return dp[i][j];


}
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int maxi=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxi=max(maxi,solve(matrix,i,j,dp));
            }
        }
        return maxi;

        
        
    }
};
