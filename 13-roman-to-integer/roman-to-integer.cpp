class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); ++i) {
            int cur = value(s[i]);

            if (i + 1 < s.size() && cur < value(s[i + 1]))
                ans -= cur;
            else
                ans += cur;
        }

        return ans;
    }

private:
    int value(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            default: return 1000;
        }
    }
};