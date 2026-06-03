class Solution {
   public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int n, m;
    int area;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        area++;
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(grid, visited, nx, ny);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxi = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    area = 0;
                    dfs(grid, visited, i, j);
                    maxi = max(area, maxi);
                }
            }
        }

        return maxi;
    }
};
