class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = bits.size() - 2;

        while (i >= 0 && bits[i] == 1) {
            i--;
        }

        return (bits.size() - 2 - i) % 2 == 0;
    }
};