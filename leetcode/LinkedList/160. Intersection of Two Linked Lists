/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
        int sizeA= 0;
        int sizeB= 0;
        
        ListNode* temp = headA;
        while(temp != NULL){
            sizeA++;
            temp = temp->next;
        }
        
        temp = headB;
        while(temp != NULL){
            sizeB++;
            temp = temp->next;
        }
        
        int diff=abs(sizeA-sizeB);
        
        ListNode* tA = headA;
        ListNode* tB = headB;
        
        if (sizeA>sizeB){
            while(diff--)
                tA = tA->next;
        }
        else{
            while(diff--)
                tB = tB->next;
        }
        
        while(tA != tB && tA!=NULL&&tB!=NULL){
            tA = tA->next;
            tB = tB ->next;
            
        }
        
        return tA;
        
    }
};
