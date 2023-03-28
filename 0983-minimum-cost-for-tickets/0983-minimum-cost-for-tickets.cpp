class Solution {
public:
    
    // declare a dp array
    
    int dp[366];
    
    int helper(vector<int>& days, int i, int n, vector<int>& costs)
    {
        // base case
        
        if(i >= n)
            return 0;
        
        // if already calculated
        
        if(dp[i] != -1)
            return dp[i];
        
        // find one day cost, seven day cost and 30 day cost 
        
        int idx_1 = lower_bound(days.begin(), days.end(), days[i] + 1) - days.begin();
        
        int one_day_cost = costs[0] + helper(days, idx_1, n, costs);
        
        int idx_7 = lower_bound(days.begin(), days.end(), days[i] + 7) - days.begin();
        
        int seven_day_cost = costs[1] + helper(days, idx_7, n, costs);
        
        int idx_30 = lower_bound(days.begin(), days.end(), days[i] + 30) - days.begin();
        
        int thirty_day_cost = costs[2] + helper(days, idx_30, n, costs);
        
        // store the res and return it
        
        return dp[i] = min({one_day_cost, seven_day_cost, thirty_day_cost});
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        
        // initialize dp with -1
        
        memset(dp, -1, sizeof(dp));
        
        return helper(days, 0, n, costs);
    }
};