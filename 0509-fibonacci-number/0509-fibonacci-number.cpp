class Solution {
public:
    unordered_map<int, int> dp;

    int fib(int n) {
        // RECC SOLUTION

        // if(n <= 0){
        //     return 0;
        // }
        // else if(n == 1){
        //     return 1;
        // }

        // int ans = fib(n-2) + fib(n-1);
        // return ans;

        //DP SOLUTION

        if(n == 0 || n == 1){
            return n;
        }

        int ans = fib(n-2) + fib(n-1);
        dp[n] = ans;

        return ans;
    }
};