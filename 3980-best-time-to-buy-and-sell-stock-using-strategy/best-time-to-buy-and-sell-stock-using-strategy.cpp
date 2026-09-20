class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> profit(n + 1, 0);
        vector<long long> priceSum(n + 1, 0);

        // Build prefix sums
        for (int i = 1; i <= n; i++) {
            profit[i] = profit[i - 1]
                      + 1LL * prices[i - 1] * strategy[i - 1];

            priceSum[i] = priceSum[i - 1] + prices[i - 1];
        }

        // Profit without any modification
        long long ans = profit[n];

        // Try every k-length window
        for (int right = k; right <= n; right++) {

            // Remove original profit of this window
            long long originalWindow =
                profit[right] - profit[right - k];

            // New profit:
            // first k/2 positions -> 0
            // last k/2 positions  -> 1
            long long modifiedWindow =
                priceSum[right] - priceSum[right - k / 2];

            long long currentProfit =
                profit[n] - originalWindow + modifiedWindow;

            ans = max(ans, currentProfit);
        }

        return ans;
    }
};