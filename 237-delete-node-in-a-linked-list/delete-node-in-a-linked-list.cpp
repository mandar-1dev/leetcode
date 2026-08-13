class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;

        while (temp->next != NULL) {
            temp->val = temp->next->val;

            if (temp->next->next == NULL) {
                temp->next = NULL;
                break;
            }

            temp = temp->next;
        }
    }
};