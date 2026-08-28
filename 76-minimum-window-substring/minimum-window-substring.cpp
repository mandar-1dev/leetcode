class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);

        // Store frequency of characters in t
        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        int required = t.size();

        for (int right = 0; right < s.size(); right++) {

            // Include current character
            if (freq[s[right]] > 0) {
                required--;
            }

            freq[s[right]]--;

            // Window contains all characters of t
            while (required == 0) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove character from left
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};