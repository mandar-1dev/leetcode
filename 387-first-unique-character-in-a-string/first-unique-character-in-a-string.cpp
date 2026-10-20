
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        // Count the frequency of each character
        for (char c : s) {
            freq[c - 'a']++;     //calculation the ascii index and storing it 
        }

        // Find the first character that occurs once
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
