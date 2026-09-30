class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
    
        for(int i = 0; i < h.size() - 1; i++) {
            int climb = h[i + 1] - h[i];
            
            if(climb <= 0) {
                continue;
            }
            
            pq.push(climb);
            
            if(pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
        
            if(bricks < 0) {
                return i;
            }
        }
        
        return h.size() - 1;
    }
};