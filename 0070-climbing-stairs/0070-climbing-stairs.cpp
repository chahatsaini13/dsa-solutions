class Solution {
public:
    unordered_map<int, int> dp;

    int steps( int i, int n){
        if(i == n){
            return 1; // same step pr hi khade ho
        }
        else if(i > n){
            return 0; // jaha jaana hai woh curr se picche hai toh jaa hi nhi skte
        }

        if(dp.find(i) != dp.end()){
            return dp[i];
        }

        int ans = steps(i+1, n) + steps(i+2, n);
        dp[i] = ans;

        return ans;
    }

    int climbStairs(int n) {
        
        if(n == 1 || n == 2){
            return n;
        }

        return steps(0, n);

    }
};