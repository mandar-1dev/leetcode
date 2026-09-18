class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n <= 1)
            return 0;

        int hold = -prices[0];
        int sold = 0;
        int cooldown = 0;

        for (int i = 1; i < n; i++) {
            int prevHold = hold;
            int prevSold = sold;
            int prevCooldown = cooldown;

            // Hold: either keep holding or buy after cooldown
            hold = max(prevHold, prevCooldown - prices[i]);

            // Sold: sell the stock today
            sold = prevHold + prices[i];

            // Cooldown: either stay in cooldown or remain after selling
            cooldown = max(prevCooldown, prevSold);
        }

        return max(sold, cooldown);
    }
};