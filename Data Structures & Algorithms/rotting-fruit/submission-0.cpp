class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Add all initially rotten oranges to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int ans = 0;

        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            ans = max(ans, t);

            for (int i = 0; i < 4; i++) {
                int row = r + nrow[i];
                int col = c + ncol[i];

                if (row >= 0 && row < n &&
                    col >= 0 && col < m &&
                    grid[row][col] == 1 &&
                    vis[row][col] != 2) {

                    vis[row][col] = 2;
                    q.push({{row, col}, t + 1});
                }
            }
        }

        // Check whether any fresh orange remains
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }

        return ans;
    }
};