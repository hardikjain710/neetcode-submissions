class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int n,m;
bool dfs(vector<vector<char>>& board,string word,vector<vector<bool>>&visited,int i,int j,int k){
    visited[i][j]=true;

    if(k==word.size()){
        return true;
    }

    for(int it=0; it<4; it++){
        int nx=dx[it]+i;
        int ny=dy[it]+j;

        if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && board[nx][ny]==word[k]){
            if(dfs(board,word,visited,nx,ny,k+1)){
                return true;
            }
        }
    }
    visited[i][j] = false;
    return false;

}

    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        bool flag=false;


        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word[0]==board[i][j]){
                vector<vector<bool>>visited(n,vector<bool>(m,false));
                    if(dfs(board,word,visited,i,j,1)){
                        return true;
                    }
                }
            }
          
        }
        return false;
    }
};
