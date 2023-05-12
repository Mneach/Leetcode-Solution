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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        
        ListNode *newHead = new ListNode();
        ListNode *prev = NULL;
        
        while(head != NULL){
            if(prev == NULL){
                prev = new ListNode(head->val);
                head = head->next;
            }else{
                newHead = new ListNode(head->val);
                newHead->next = prev;
                prev = newHead;
                head = head->next;                
            } 

        }
        
        return newHead;
    }
};