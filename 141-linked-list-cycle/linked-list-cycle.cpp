
class Solution {
public:
    bool hasCycle(ListNode *head) {

        

        ListNode *slow = head;
         ListNode *fast = head;
         
        if(slow == NULL || slow->next == NULL ) return false;

        while(fast != NULL && fast->next != NULL){
          
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
            if(slow == fast) return true; 
        }      
        return false;

        
         
    }
};