class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_ele[256];
        memset(last_ele, -1, sizeof(last_ele));

        int left = 0, answer = 0;

        for (int right = 0; right < s.size(); right++) {
            if (last_ele[s[right]] >= left) {
                left = last_ele[s[right]] + 1;
            }

            last_ele[s[right]] = right;
            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};