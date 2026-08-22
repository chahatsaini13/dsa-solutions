class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        for(int k = 0; k < n; k++){
            sum += arr[k];
        }

        if(sum % 2 != 0){
            return false;
        }else{
            sum = sum/2;
        }

        vector<vector<int>> dp(n+1);

        for(int i = 0; i  <= n; i++){
            vector<int> t(sum+1, -1);
            dp[i] = t;
        }

        for(int j = 0; j <= sum; j++){
            dp[n][j] = 0;
        }
        dp[n][0] = 1;

        for(int i = n-1; i >= 0; i--){

            for(int j = 0; j <= sum; j++){

                if(arr[i] > j){
                    dp[i][j] = dp[i+1][j];
                }
                else{
                    dp[i][j] = (dp[i+1][j - arr[i]]) || (dp[i+1][j]);
                }
            }
        }

        return dp[0][sum];
    }
};