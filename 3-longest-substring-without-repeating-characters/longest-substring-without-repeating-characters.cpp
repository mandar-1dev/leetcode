class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    // if (s.size() == 1)
    //     return 1;
    // set<char> sub;
    // int len = 0;
    // int start_pos = 0;
    // bool state = false;
    // for (int i = start_pos; i < s.size(); ++i) {
    //     state = sub.insert(s[i]).second;
    //     if (sub.size() > len)
    //         len = sub.size();
    //     if (!state) {
    //         sub.clear();
    //         i = start_pos;
    //         ++start_pos;
    //     }
    //     // for (int j = 0; j < sub.size(); ++j) {
    //     //     for (int k = 0; k < sub.size(); ++k) {
    //     //         if (j != k && sub[j] == sub[k]) {
    //     //             sub.clear();
    //     //             i = start_pos;
    //     //             ++start_pos;
    //     //         }
    //     //     }
    //     // }
    //     // if (sub.size() > len)
    //     //     len = sub.size();
    // }
    // return len;
    std::vector<int> last_seen(256, -1);
    
    int max_len = 0;
    int start = 0; // Left pointer of sliding window

    for (int end = 0; end < s.length(); ++end) {
        char current_char = s[end];

        // If character was seen after current 'start', update 'start'
        if (last_seen[current_char] >= start) {
            start = last_seen[current_char] + 1;
        }

        // Update last seen index of the current character
        last_seen[current_char] = end;

        // Calculate max window length
        max_len = std::max(max_len, end - start + 1);
    }

    return max_len;
    }
};