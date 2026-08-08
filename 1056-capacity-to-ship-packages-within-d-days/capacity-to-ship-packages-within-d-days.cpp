class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysUsed = 1;
        int currentWeight = 0;

        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                daysUsed++;
                currentWeight = weight;
            } else {
                currentWeight += weight;
            }
        }

        return daysUsed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                high = mid;       // Try smaller capacity
            } else {
                low = mid + 1;    // Need larger capacity
            }
        }

        return low;
    }
};