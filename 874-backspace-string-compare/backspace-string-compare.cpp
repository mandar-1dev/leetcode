class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string one;
        string two;

        for (char c : s) {
            if (c == '#') {
                if (!one.empty()) {
                    one.pop_back();
                }
            } else {
                one += c;
            }
        }

        for (char c : t) {
            if (c == '#') {
                if (!two.empty()) {
                    two.pop_back();
                }
            } else {
                two += c;
            }
        }

        return one == two;
    }
};