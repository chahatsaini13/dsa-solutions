class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool isvalid(int i, int j, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

    int dfs(vector<vector<int>>& grid, int r, int c,
            int n, int m, int id) {

        grid[r][c] = id;

        int size = 1;

        for(int k = 0; k < 4; k++) {

            int row = r + x[k];
            int col = c + y[k];

            if(isvalid(row, col, n, m) &&
               grid[row][col] == 1) {

                size += dfs(grid, row, col, n, m, id);
            }
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<int> sizes(2, 0);

        int id = 2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {

                    int currSize = dfs(
                        grid, i, j, n, n, id
                    );

                    sizes.push_back(currSize);
                    id++;
                }
            }
        }

        int res = 0;

        // Try changing every 0 to 1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] != 0) {
                    res = max(res, sizes[grid[i][j]]);
                    continue;
                }

                int curr = 1;

                set<int> seen;

                for(int k = 0; k < 4; k++) {

                    int row = i + x[k];
                    int col = j + y[k];

                    if(isvalid(row, col, n, n) &&
                       grid[row][col] >= 2) {

                        int id = grid[row][col];

                        if(!seen.count(id)) {
                            curr += sizes[id];
                            seen.insert(id);
                        }
                    }
                }

                res = max(res, curr);
            }
        }

        return res;
    }
};