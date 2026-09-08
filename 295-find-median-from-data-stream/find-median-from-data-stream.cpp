class MedianFinder {
public:
    priority_queue<int> left; // Max heap
    priority_queue<int, vector<int>, greater<int>> right; // Min heap

    MedianFinder() {
    }

    void addNum(int num) {

        // Step 1: Put number in the correct heap
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } 
        else {
            right.push(num);
        }

        // Step 2: Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        // Even number of elements
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }

        // Odd number of elements
        return left.top();
    }
};