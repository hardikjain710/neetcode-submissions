class Solution {
   public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    int n, m;
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] &&
                board[nx][ny] == 'O') {
                dfs(board, visited, nx, ny);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, visited, i, 0);
            }
            if (board[i][m - 1] == 'O' && !visited[i][m - 1]) {
                dfs(board, visited, i, m - 1);
            }
        }

        for (int j = 1; j < m - 1; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                dfs(board, visited, 0, j);
            }
            if (board[n - 1][j] == 'O' && !visited[n - 1][j]) {
                dfs(board, visited, n - 1, j);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
