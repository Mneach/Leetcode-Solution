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
        
        ListNode *newHead = NULL;
        ListNode *temp = NULL;
        
        while(head != NULL){
            newHead = new ListNode(head->val);
            newHead->next = temp;
            temp = newHead;
            head = head->next;
        }
        
        return newHead;
    }
};