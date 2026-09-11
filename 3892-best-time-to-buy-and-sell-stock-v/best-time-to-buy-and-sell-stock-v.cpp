class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        // dp[j][0] = nothing held
        // dp[j][1] = holding a normal stock
        // dp[j][2] = holding a short position
        vector<vector<long long>> dp(k + 1, vector<long long>(3, 0));

        for (int j = 1; j <= k; j++) {
            dp[j][1] = -prices[0]; // buy
            dp[j][2] = prices[0];  // short sell
        }

        for (int i = 1; i < n; i++) {
            vector<vector<long long>> next = dp;

            for (int j = 1; j <= k; j++) {

                // Do nothing
                next[j][0] = max({
                    dp[j][0],
                    dp[j][1] + prices[i], // sell normal stock
                    dp[j][2] - prices[i]  // buy back short
                });

                // Hold normal stock
                next[j][1] = max(
                    dp[j][1],
                    dp[j - 1][0] - prices[i] // buy
                );

                // Hold short position
                next[j][2] = max(
                    dp[j][2],
                    dp[j - 1][0] + prices[i] // short sell
                );
            }

            dp = next;
        }

        return dp[k][0];
    }
};