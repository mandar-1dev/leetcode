class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        // Sort by height descending.
        // If heights are same, sort by k ascending.
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<vector<int>> ans;

        // Insert each person at their k-th position.
        for (auto person : people) {
            ans.insert(ans.begin() + person[1], person);
        }

        return ans;
    }
};