class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1);

        for(int i = 0; i <= n; i++){
            vector<int> t((2*k)+1);
            dp[i] = t;
        }

        for(int j = 0; j < ((2*k)+1); j++){
            dp[0][j] = 0;
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j < ((2*k)+1); j++){
                if(j % 2 == 0){
                    dp[i][j] = max((dp[i+1][j-1] - prices[i]), dp[i+1][j]);
                }
                else{
                    dp[i][j] = max((dp[i+1][j-1] + prices[i]), dp[i+1][j]);
                }
            }
        }

        return dp[0][k*2];
    }
};