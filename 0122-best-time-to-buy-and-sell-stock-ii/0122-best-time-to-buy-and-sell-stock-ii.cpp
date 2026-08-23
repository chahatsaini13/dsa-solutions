class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1);

        for(int i = 0; i <= n; i++){
            vector<int> t(3);
            dp[i] = t;
        }

        for(int j = 0; j < 3; j++){
            dp[0][j] = 0;
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = 1; j < 3; j++){
                if(j == 2){
                    dp[i][j] = max((dp[i+1][j-1] - prices[i]), dp[i+1][j]);
                }
                else{
                    dp[i][j] = max((dp[i+1][2] + prices[i]), dp[i+1][j]);
                }
            }
        }

        return dp[0][2];
    }
};