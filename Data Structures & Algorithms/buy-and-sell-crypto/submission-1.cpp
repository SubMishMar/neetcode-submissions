class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = std::numeric_limits<int>::min();
        for(int i = 0; i < prices.size(); ++i){
            for(int j = i+1; j < prices.size(); ++j) {
                int current_profit = prices[j]-prices[i];
                if(current_profit > profit){
                    profit = current_profit;
                }
            }
        }
        if(profit>0){
            return profit;
        }
        return 0;
    }
};
