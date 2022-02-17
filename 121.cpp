class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, maxProfit = 0;
        for(int i = 1; i < n; i++) {
            if(prices[l] <= prices[i]) {
                int profit = prices[i] - prices[l];
                maxProfit = max(maxProfit, profit);
            }
            else l = i;
        }
        return maxProfit;
    }
};