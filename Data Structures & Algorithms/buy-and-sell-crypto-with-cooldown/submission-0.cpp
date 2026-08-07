class Solution {
public:
    unordered_map<string, int> dp; //cachin
    
    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);
    }

    int dfs(int i, bool buying, vector<int>& prices){
        if(i >= prices.size()){
            return 0;
        }

        string key = to_string(i) + "-" + to_string(buying);
        if(dp.find(key) != dp.end()){
            return dp[key];
        }

        int cooldown = dfs(i+1, buying, prices);
        if(buying){
            int buy = dfs(i+1, !buying, prices) - prices[i]; //why false(!buying) - in question - you must sell the stock before you buy again
            dp[key] = max(buy,cooldown);
        }
        else{
            int sell = dfs(i+2, !buying, prices) + prices[i]; //why i+2 - cooldown day
            dp[key] = max(sell, cooldown);
        }

        return dp[key];
    }
};
