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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* curr = head -> next;
        ListNode* answer = head;

        while(curr != NULL && curr -> next != NULL){
            if(curr->val == 0){
                answer->next = curr;
                answer = curr;
            }else{
                answer->val += curr -> val;
            }

            curr = curr -> next;
        }

        answer -> next = NULL;

        return head;

    }
};