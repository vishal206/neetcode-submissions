class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0,sell=0;
        int profit=0;
        
        while(sell<prices.size()){
            if(profit<prices[sell]-prices[buy]){
                profit = prices[sell]-prices[buy];
            }
            if(prices[buy]>prices[sell]){
                buy=sell;
            }
            sell++;
        }

        return profit;
    }
};
