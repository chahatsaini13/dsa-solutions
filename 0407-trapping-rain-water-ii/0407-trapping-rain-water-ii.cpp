class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ans = 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0 || j == n-1){
                    pq.push({heightMap[i][j] , {i, j}});
                    vis[i][j] = true;
                    continue;
                }
                else if(i == 0 || i == m-1){
                    pq.push({heightMap[i][j] , {i, j}});
                    vis[i][j] = true;
                    continue;
                }
            }
        }

        while(!pq.empty()) {
            auto [height, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            int x[4] = {-1, 1, 0, 0};
            int y[4] = {0, 0, -1, 1};

            for(int k = 0; k < 4; k++){
                int row = r + x[k];
                int col = c + y[k];

                if(row < 0 || row >= m || col < 0 || col >= n)
                    continue;

                if(vis[row][col])
                    continue;

                vis[row][col] = true;

                if(heightMap[row][col] < height){
                    ans += height - heightMap[row][col];
                }

                pq.push({max(height, heightMap[row][col]), {row, col}});
            }
        }

        return ans;
    }
};