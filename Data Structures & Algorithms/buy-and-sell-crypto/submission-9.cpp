class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int i = 0;
        int j = 1;
        while(j < prices.size()){
            int profit = prices[j] - prices[i];
            if(profit >= 0){
                max_profit = max(max_profit, profit);
            } else {
                i = j;
            }
            j++;
        }
        return max_profit;
    }
};
