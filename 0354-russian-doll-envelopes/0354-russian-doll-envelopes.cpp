class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {
            if(a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        });

        vector<int> lis;

        for(int i = 0; i < envelopes.size(); i++) {
            int height = envelopes[i][1];
            int low = 0;
            int high = lis.size();

            while(low < high) {
                int mid = (low + high) / 2;

                if(lis[mid] < height) {
                    low = mid + 1;
                }
                else {
                    high = mid;
                }
            }

            if(low == lis.size()) {
                lis.push_back(height);
            }
            else {
                lis[low] = height;
            }
        }

        return lis.size();
    }
};