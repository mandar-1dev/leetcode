class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> st;

        while (head) {
            while (!st.empty() && st.back()->val < head->val) {
                st.pop_back();
            }

            st.push_back(head);
            head = head->next;
        }

        for (int i = 0; i + 1 < st.size(); i++) {
            st[i]->next = st[i + 1];
        }

        st.back()->next = nullptr;

        return st[0];
    }
};