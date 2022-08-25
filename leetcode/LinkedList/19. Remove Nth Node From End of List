/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while(n--&&fast!=NULL)
            fast = fast->next;
        fast = fast->next;
        while(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return dummyHead->next;
    }
    
};
