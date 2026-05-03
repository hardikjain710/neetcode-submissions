class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> pq;
        int n = grid.size();
        int m = grid[0].size();
        int f = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    pq.push({i, j});
                } else if (grid[i][j] == 1) {
                    f++;
                }
            }
        }

        int min = 0;
        if (f == 0) {
            return min;
        }
        while (!pq.empty()) {
            bool flag = false;
            int s = pq.size();
            for (int i = 0; i < s; i++) {
                auto [x, y] = pq.front();
                pq.pop();

                if (x + 1 < n && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    pq.push({x + 1, y});
                    flag = true;
                    f--;
                }
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    pq.push({x - 1, y});
                    flag = true;
                    f--;
                }

                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    pq.push({x, y - 1});
                    flag = true;
                    f--;
                }
                if (y + 1 < m && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    pq.push({x, y + 1});
                    flag = true;
                    f--;
                }
            }
            if (flag) {
                min++;
            }
        }

        if (f == 0) {
            return min;
        }
        return -1;
    }
};
