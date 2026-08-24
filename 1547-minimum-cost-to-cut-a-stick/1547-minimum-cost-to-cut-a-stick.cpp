class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();

        vector<int> c;
        c.push_back(0);
        for(int i = 0; i < m; i++){
            c.push_back(cuts[i]);
        }
        c.push_back(n);
        sort(c.begin(), c.end());
        
        int s = c.size();
        vector<vector<int>> dp(s, vector<int>(s, 0));

        for(int i = s - 2; i >= 1; i--){
            for(int j = i; j <= s - 2; j++){

                int res = INT_MAX;

                for(int k = i; k <= j; k++){

                    int cost = c[j+1] - c[i-1];

                    int r = cost + dp[i][k-1] + dp[k+1][j];
                    
                    res = min(res, r);
                }

                dp[i][j] = res;
            }
        }

        return dp[1][s-2];
    }
};