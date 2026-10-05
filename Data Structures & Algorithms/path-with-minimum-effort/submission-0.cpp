class Solution {
   public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();

            if (visited[x][y]) continue;

            visited[x][y] = true;
            if (x == n - 1 && y == m - 1) {
                return -1 * dist;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny < m && ny >= 0 && !visited[nx][ny]) {
                    int d = max(abs(heights[nx][ny] - heights[x][y]), -1 * dist);
                    pq.push({-1 * d, {nx, ny}});
                }
            }
        }
        return 0;
    }
};