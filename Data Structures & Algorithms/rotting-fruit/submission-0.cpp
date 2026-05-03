class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        priority_queue<pair<int,int>>pq;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    pq.push({i,j});
                }
            }
        }

        int min=0;
        while(!pq.empty()){
            auto [x,y]=pq.top();
            bool flag=false;
            pq.pop();

            if(x+1<n && grid[x+1][y]==1){
                grid[x+1][y]=2;
                pq.push({x+1,y});

            }
            if(x-1>=0 && grid[x-1][y]==1){
                grid[x-1][y]=2;
                pq.push({x-1,y});
                flag=true;
            }

            if(y-1>=0 && grid[x][y-1]==1){
                grid[x][y-1]=2;
                pq.push({x,y-1});
                flag=true;
            }
            if(y+1<m && grid[x][y+1]==1){
                grid[x][y+1]=2;
                pq.push({x,y+1});
                flag=true;
            }
            if(flag){
                min++;
            }




        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return min;

    }
};
