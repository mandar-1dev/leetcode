class Solution {
public:
    bool canArrive(vector<int>& dist, double hour, int speed) {
        double totalTime = 0;

        int n = dist.size();

        for (int i = 0; i < n; i++) {

            double time = (double)dist[i] / speed;

            // For all trains except the last one,
            // we must wait until the next integer hour.
            if (i != n - 1) {
                totalTime += ceil(time);
            }
            else {
                // Last train: no need to wait.
                totalTime += time;
            }
        }

        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        int low = 1;
        int high = 10000000;

        // Binary search
        while (low < high) {

            int mid = low + (high - low) / 2;

            if (canArrive(dist, hour, mid)) {
                // mid works, so try a smaller speed
                high = mid;
            }
            else {
                // mid doesn't work, need higher speed
                low = mid + 1;
            }
        }

        // Check whether even maximum speed works
        if (!canArrive(dist, hour, low)) {
            return -1;
        }

        return low;
    }
};