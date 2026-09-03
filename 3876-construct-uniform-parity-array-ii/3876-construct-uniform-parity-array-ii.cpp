class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int min_val = nums[0];
        int odd_count = 0;

        for (int x : nums) {
            if (x < min_val) min_val = x;
            if (x % 2 != 0) odd_count++;
        }

        // If all elements are already odd or all are even
        if (odd_count == nums.size() || odd_count == 0) return true;

        // An array can always be made uniform if the minimum element is odd
        return (min_val % 2 != 0);
        
    }
};