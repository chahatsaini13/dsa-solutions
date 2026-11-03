class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int apt = values[0];  

        for(int j = 1; j < values.size(); j++) {

            ans = max(ans, apt + values[j] - j);

            apt = max(apt, values[j] + j);
        }

        return ans;
    }
};