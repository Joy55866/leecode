class Solution {
public
    typedef long long ll;
    int minRefuelStops(int target, int startFuel, vectorvectorint& stations) {
        if(startFuel = target) return 0;
        
        stations.push_back({0, startFuel});
        int n = stations.size();
        int min_val = INT32_MAX;
        vectorvectorll dp(n+1, vectorll(n+1, 0));
        
        sort(stations.begin(), stations.end());
        
        dp[0][0] = startFuel;
        
        for(int i = 1; i  n; i++)
        {
            for(int j = 0 ; j = i; j++)
            {
                if(dp[i-1][j] = stations[i][0]) {
                    dp[i][j] = dp[i-1][j];
                } 
                if((j  0) && (dp[i-1][j-1] = stations[i][0])) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stations[i][1]);
                }
                if(dp[i][j] = target) {
                    min_val = min(min_val, j);
                }
            }
        }
        
        
        for(int i = 1 ; i  n; i++)
        {
            for(int j = 0 ; j  i; j++)
            {
                for(int k = 0 ; k  n; k++)
                {
                    if(dp[j][k] = stations[i][0])
                    {
                        dp[i][k+1] = max(dp[i][k+1], dp[j][k] + stations[i][1]);
                        if(dp[i][k+1] = target) {
                            min_val = min(min_val, k+1);
                        }
                    }
                }
            }
        }
        return (min_val == INT32_MAX)  -1  min_val;
    }
};