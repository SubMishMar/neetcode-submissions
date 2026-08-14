class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int j = i+1;
        int max_profit = 0;
        while(j<prices.size()){
            int profit =  prices[j]-prices[i];
            if (profit > 0) {
                max_profit = std::max(max_profit, profit);
            } else {
                i = j;
            } 
            j++;
        }
        return max_profit;
    }
};
