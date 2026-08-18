class Solution {
public:
    int max_of(vector<vector<int>>& grid, int n, int m){
        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxi = max(maxi, grid[i][j]);
            }
        }

        return maxi;
    }

    bool isvalid(int r, int c, int n, int m) {
        if(r < 0 || c < 0 || r >= n || c >= m){
            return false;
        }

        return true;
    }

    bool bfs(vector<vector<int>>& grid, int n, int m, int g){
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n);
        
        for(int i = 0;  i < n; i++){
            vector<int> t(m, 0);
            vis[i] = t;
        }

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            int row = p.first, col = p.second;

            if(row == n-1 && col == m-1){
                return true;
            }

            for(int k = 0; k < 4; k++){
                int r = row + x[k];
                int c = col + y[k];

                if(isvalid(r, c, n, m) && vis[r][c] == 0 && g >= grid[r][c]){
                    q.push({r,c});
                    vis[r][c] = 1;
                }
            }
        }

        return false;;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =  grid[0].size();

        int low = grid[0][0];
        int high = max_of(grid, n, m);
        int res = 0;

        while(low <= high){
            int guess = (low + high) / 2;

            if(bfs(grid, n, m, guess)){
                res = guess;
                high = guess - 1;
            }else{
                low = guess + 1;
            }
        }

        return res;

    }
};