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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* curr = head;
        ListNode* curr2 = head;

        while(curr2 != NULL && curr2->next != NULL){
            curr = curr->next;
            curr2 = curr2->next->next;
            if(curr == curr2) return true;
        }

        return false;
    }
};