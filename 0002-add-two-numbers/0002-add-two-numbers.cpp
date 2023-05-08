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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode();
        ListNode* curr = head;

        int carry = 0;
        int addition = 0;
        while(true){
            if(l1 != NULL){
                addition += l1->val;
            }
            
            if(l2 != NULL){
                addition += l2->val;
            }

            if(carry != 0){
                addition += carry;
                carry = 0;
            }

            if(addition >= 10) {
                carry = addition / 10;
                addition %= 10;
            }

            if(l1 == NULL && l2 == NULL) break;

            curr->next = new ListNode(addition);
            curr = curr->next;

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            addition = 0;
        }

        if(addition > 0){
            curr->next = new ListNode(addition);
            curr = curr->next;
        }

        return head->next;
    }
};

