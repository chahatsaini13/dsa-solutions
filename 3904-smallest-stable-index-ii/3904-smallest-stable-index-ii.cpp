class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> pre(nums.size());
        vector<int> suf(nums.size());

        pre[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            pre[i] = max(pre[i - 1], nums[i]);
        }

        suf[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--){
            suf[i] = min(suf[i + 1], nums[i]);
        }

        for(int i = 0; i < nums.size(); i++){
            if(pre[i] - suf[i] <= k){
                return i;
            }
        }

        return -1;
    }
};