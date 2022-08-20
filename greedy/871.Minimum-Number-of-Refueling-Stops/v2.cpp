class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int stops = 0; //how many stop currently.
        int cur = startFuel; // how many miles we can reach currently.
        
        priority_queue<int, vector<int>, less<int>> pq;
        stations.push_back({target, 0});
        
        for(int i = 0 ; i < stations.size(); i++)
        {
            while((cur < stations[i][0]) && !pq.empty()) {
                cur += pq.top();
                pq.pop();
                stops++;
            }
            if(cur < stations[i][0]) {
                return -1;
            }
            
            pq.push({stations[i][1]});
        }
    
        return stops;
    }
};