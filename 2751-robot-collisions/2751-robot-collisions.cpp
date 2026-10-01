class Solution {
public:
    static bool cmp(tuple<int, int, char, int> a,
                    tuple<int, int, char, int> b) {
        return get<0>(a) < get<0>(b);
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths,string directions) {
        vector<int> res(positions.size());
        vector<tuple<int, int, char, int>> correct;

        for(int i = 0; i < positions.size(); i++) {
            correct.push_back({
                positions[i],
                healths[i],
                directions[i],
                i
            });
        }

        sort(correct.begin(), correct.end(), cmp);

        stack<tuple<int, char, int>> st;

        for(auto rob : correct) {
            int heal = get<1>(rob);
            char dir = get<2>(rob);
            int index = get<3>(rob);

            if(dir == 'R') {
                st.push({heal, dir, index});
                continue;
            }

            bool alive = true;

            while(!st.empty() && get<1>(st.top()) == 'R' && alive) {
                int prev = get<0>(st.top());

                if(prev < heal) {
                    st.pop();
                    heal--;
                }
                else if(prev == heal) {
                    st.pop();
                    alive = false;
                }
                else {
                    get<0>(st.top())--;
                    alive = false;
                }
            }

            if(alive) {
                st.push({heal, 'L', index});
            }
        }

        while(!st.empty()) {
            int heal = get<0>(st.top());
            int idx = get<2>(st.top());

            res[idx] = heal;
            st.pop();
        }

        vector<int> ans;

        for(int i = 0; i < res.size(); i++) {
            if(res[i] != 0) {
                ans.push_back(res[i]);
            }
        }

        return ans;
    }
};