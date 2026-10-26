class Solution {
public:
    int rows, cols;
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    long long dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= rows || c >= cols) {
            return 0;
        }

        if (grid[r][c] == 0) {
            return 0;
        }

        long long sum = grid[r][c];

        grid[r][c] = 0;

        for (int k = 0; k < 4; k++) {
            int row = r + x[k];
            int col = c + y[k];

            sum += dfs(grid, row, col);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();
        int ans = 0;
    
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != 0) {
                    if (dfs(grid, r, c) % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};