class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int n,m;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        const int I=2147483647;

        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            pair<pair<int, int>, int> c= q.front();
            int x=c.first.first;
            int y=c.first.second;
            int d=c.second;
            q.pop();

            for(int k=0; k<4; k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==I){
                    grid[nx][ny]=d+1;
                    q.push({{nx,ny},d+1});
                }
            }
        
        }

        
    }
};










