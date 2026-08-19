class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& list) {
        unordered_map<string, int> f;

        for(int i = 0; i < list.size(); i++){
            f[list[i]] = i;
        }

        if(f.find(begin) == f.end()){
            f[begin] = 1;
        }

        if(!f.contains(end)){
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({begin, 1});
        f.erase(begin);
        
        while(!q.empty()){
            pair<string, int> p = q.front();
            q.pop();

            string s = p.first;
            int val = p.second;

            if(s == end){
                return val;
            }

            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                for(int j = 97; j <= 122; j++){
                    if(c == j){
                        continue;
                    }

                    s[i] = j;

                    if(f.find(s) != f.end()){
                        q.push({s, val+1});
                        f.erase(s);
                    }
                }

                s[i] = c;
            }
        }

        return 0;
    }
};