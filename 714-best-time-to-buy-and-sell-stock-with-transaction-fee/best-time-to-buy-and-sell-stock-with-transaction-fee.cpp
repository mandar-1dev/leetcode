class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int prevCash = cash;

            // Sell the stock
            cash = max(cash, hold + prices[i] - fee);

            // Buy the stock
            hold = max(hold, prevCash - prices[i]);
        }

        return cash;
    }
};