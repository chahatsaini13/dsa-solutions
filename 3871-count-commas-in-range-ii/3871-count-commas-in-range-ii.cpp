class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000){
            return 0;
        }

        long long ans = 0;

        // 1 comma
        if(n >= 1000){
            long long end = min(n, 999999LL);
            ans += (end - 1000 + 1) * 1;
        }

        // 2 commas
        if(n >= 1000000){
            long long end = min(n, 999999999LL);
            ans += (end - 1000000 + 1) * 2;
        }

        // 3 commas
        if(n >= 1000000000){
            long long end = min(n, 999999999999LL);
            ans += (end - 1000000000 + 1) * 3;
        }

        // 4 commas
        if(n >= 1000000000000LL){
            long long end = min(n, 999999999999999LL);
            ans += (end - 1000000000000LL + 1) * 4;
        }

        // 5 commas
        if(n >= 1000000000000000LL){
            ans += (n - 1000000000000000LL + 1) * 5;
        }

        return ans;
    }
};