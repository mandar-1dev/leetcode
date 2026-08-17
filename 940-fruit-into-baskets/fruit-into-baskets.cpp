// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         unordered_map<int, int> freq;

//         int left = 0;
//         int ans = 0;

//         for (int right = 0; right < fruits.size(); right++) {
//             freq[fruits[right]]++;

//             while (freq.size() > 2) {
//                 freq[fruits[left]]--;

//                 if (freq[fruits[left]] == 0) {
//                     freq.erase(fruits[left]);
//                 }

//                 left++;
//             }

//             ans = max(ans, right - left + 1);
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int b1 = -1;
        int b2 = -1;

        int ans = 0;
        int i = 0;

        for (int j = 0; j < fruits.size(); j++) {

            // First fruit type
            if (b1 == -1 || b1 == fruits[j]) {
                b1 = fruits[j];
            }

            // Second fruit type
            else if (b2 == -1 || b2 == fruits[j]) {
                b2 = fruits[j];
            }

            // Third fruit type
            else {
                i = j - 1;

                while (i >= 0 && fruits[i] == fruits[j - 1]) {
                    i--;
                }

                i++;

                b1 = fruits[j - 1];
                b2 = fruits[j];
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};