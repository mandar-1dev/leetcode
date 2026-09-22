class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 1: Detect whether cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle found

                // Step 2: Find cycle starting point
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        // No cycle
        return nullptr;
    }
};