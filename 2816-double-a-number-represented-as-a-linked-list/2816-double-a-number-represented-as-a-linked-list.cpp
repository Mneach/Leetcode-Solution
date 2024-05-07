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
    
    ListNode* doubleIt(ListNode* head) {
        
        if(head == NULL) return head;
        
        ListNode* curr = head;
        ListNode* newHead = NULL;
        ListNode* prev = NULL;
        
        //reverse the linked to fullfill the answer
        while(curr != NULL){
            newHead = new ListNode(curr->val);
            newHead->next = prev;
            prev = newHead;
            curr = curr->next;
        }
        
        // do the doubling operation
        curr = newHead;
        int carry = 0;
        while(curr != NULL){
            int result = (curr->val * 2) + carry;
            carry = result / 10;
            
            int save = result % 10;
            curr->val = save;
            
            curr = curr -> next;
        }
        
        // there is a carry like in case 999 * 2
        
        // need to reverse again to get the answers
        curr = newHead;
        prev = NULL;
        
        while(curr != NULL){
            head = new ListNode(curr -> val);
            head->next = prev;
            prev = head;
            curr = curr -> next;
        }
        
        if(carry != 0){
            ListNode* newCarry = new ListNode(carry);
            newCarry -> next = head;
            return newCarry;
        }
        
        return head;
    }
};