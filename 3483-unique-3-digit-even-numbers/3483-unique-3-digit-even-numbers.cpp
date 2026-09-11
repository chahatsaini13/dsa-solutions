class Solution {
public:
    void unique(vector<int>& digits, vector<int>& arr, 
                vector<int>& vis, set<int>& st) {
        
        if(arr.size() == 3) {
            if(arr[2] % 2 == 0) {
                int num = arr[0] * 100 + arr[1] * 10 + arr[2];
                st.insert(num);
            }
            return;
        }

        for(int i = 0; i < digits.size(); i++) {
            
            if(vis[i] == 0) {

                if(arr.size() == 0 && digits[i] == 0) {
                    continue;
                }

                vis[i] = 1;
                arr.push_back(digits[i]);

                unique(digits, arr, vis, st);

                arr.pop_back();
                vis[i] = 0;
            }
        }
    }

    int totalNumbers(vector<int>& digits) {
        vector<int> vis(digits.size(), 0);
        vector<int> arr;
        set<int> st;

        unique(digits, arr, vis, st);

        return st.size();
    }
};