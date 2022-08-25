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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        
        ListNode* front = dummyHead;
        
        int count = k;
        
        while(k-- && fast!=NULL)
            fast = fast->next;
        
        while (fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        while(count--)
            front = front->next;
        
        int temp = front->val;
        front->val = slow->val;
        slow->val = temp;
        
        return dummyHead->next;
        
    }
};
