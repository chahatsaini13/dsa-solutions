class Solution {
public:
    int maxof(vector<int> arr){
        int m = INT_MIN;

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > m){
                m = arr[i];
            }
        }

        return m;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector< pair<int,int>>> adj(n+1);
        vector<int> secs(n+1, INT_MAX);

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        secs[k] = 0;

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();

            int t = p.first;
            int node = p.second;

            if(t > secs[node]){
                continue;
            }

            for(int i = 0; i < adj[node].size(); i++){
                int neigh = adj[node][i].first;
                int s = adj[node][i].second;
                
                if(s + t < secs[neigh]){
                    secs[neigh] = s + t;
                    pq.push({s+t, neigh});
                }
            }
        }

        for(int j = 1; j <= n; j++){
            if(secs[j] == INT_MAX){
                return -1;
            }
        }

        return maxof(secs);
    }
};