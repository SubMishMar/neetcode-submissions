class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Method 1: Brute Force
        // int profit = std::numeric_limits<int>::min();
        // for(int i = 0; i < prices.size(); ++i){
        //     for(int j = i+1; j < prices.size(); ++j) {
        //         int current_profit = prices[j]-prices[i];
        //         if(current_profit > profit){
        //             profit = current_profit;
        //         }
        //     }
        // }
        // if(profit>0){
        //     return profit;
        // }
        // return 0;
        // Method 2 (Sliding window)
        int l = 0;
        int r = 1;
        int max_profit = 0;
        while(r<prices.size()) {
            int profit = prices[r]-prices[l];
            if(profit > 0){
                max_profit = std::max(max_profit, profit);
            }else{
                l = r;
            }
            r++;
        }
        return max_profit;
    }
};
