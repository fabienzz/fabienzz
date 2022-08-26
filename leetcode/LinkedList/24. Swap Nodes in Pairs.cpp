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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        
        while(cur->next != NULL && cur->next->next != NULL){
            ListNode* sui = cur->next;
            ListNode* dsui = cur->next->next->next;
            
            cur->next = sui->next;
            cur->next->next = sui;
            sui->next = dsui;
            cur = sui;
        }
        
        return dummyHead->next;
        
    }
};
