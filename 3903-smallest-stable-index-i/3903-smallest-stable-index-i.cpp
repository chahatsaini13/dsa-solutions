class Solution {
public:
    int maxs(vector<int>& nums, int idx){
        int maxi = INT_MIN;
        for(int i = 0; i <= idx; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }
        return maxi;
    }

    int mins(vector<int>& nums, int idx){
        int mini = INT_MAX;
        for(int i = idx; i < nums.size(); i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
        }
        return mini;
    }

    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            int m = maxs(nums, i);
            int n = mins(nums,i);
            res.push_back(m-n);
        }

        for(int i = 0; i < nums.size(); i++){
            if(res[i] <= k){
                return i;
            }
        }

        return -1;
    }
};