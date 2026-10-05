class Solution {
public:
    int pairSum(ListNode* head) {
        // 1. Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // prev = head of reversed second half
        // head = head of first half

        // 3. Calculate twin sums
        int ans = 0;
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {
            ans = max(ans, first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return ans;
    }
};