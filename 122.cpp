class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, maxProfit = 0;
        for(int i = 1; i < n; i++, l++) {
            if(prices[l] <= prices[i]) {
                int profit = prices[i] - prices[l];
                maxProfit += profit;
            }
        }
        return maxProfit;
    }
};