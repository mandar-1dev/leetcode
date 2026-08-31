class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> arr(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {

            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prev = st.top();
                st.pop();

                arr[prev] = i - prev;
            }

            st.push(i);
        }

        return arr;
    }
};