class Solution {
private:
    int gcd(int a, int b){

        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

public:
    // ax + by = gcd(a,b)
    bool isGoodArray(vector<int>& nums) {
        
        int g = nums[0];

        for(int x : nums) {
            g = gcd(g, x);

            if(g == 1){
                return true;
            }
        }

        return g == 1;
    }
};