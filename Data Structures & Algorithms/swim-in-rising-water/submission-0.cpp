class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int n;
bool dfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int i,int j,int t){
    if(i>=n || i<0 || j>=n || j<0 || grid[i][j]>t || visited[i][j]){
        return false;
    }
    visited[i][j]=true;
    if(i==n-1 && j==n-1){
        return true;
    }
    for(int k=0; k<4; k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(dfs(grid,visited,nx,ny,t)){
            return true;
        }
    }
    return false;

}
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        int l=grid[0][0];
        int r=n*n-1;
        int result=0;
        

        while(l<=r){
            vector<vector<bool>>visited(n,vector<bool>(n,false));
            int mid=l+(r-l)/2;
            if(dfs(grid,visited,0,0,mid)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }


        }
    return result;
    }

};
