class Solution {
public:
int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
void dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
    visited[i][j]=true;

    for(int k=0; k<4; k++){
        int nx=i+dx[k];
        int ny=j+dy[k];
        if(nx>=0 && nx<n && ny<m && ny>=0 && !visited[nx][ny] && grid[nx][ny]=='1'){
            dfs(grid,visited,nx,ny);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {

        int cnt=0;
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] =='1' && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
