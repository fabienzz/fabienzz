class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)
            return head;
  
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* met = NULL;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast =fast->next->next;
            if (slow == fast){
                met = fast;
                break;
            }
        }
        
        slow = head;
        if (met != NULL){
            while(slow!=met){
                slow = slow->next;
                met = met->next;
            }
            return slow;
        }
            
        return NULL;
    }
};
