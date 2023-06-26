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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* answer = new ListNode(head->val);
        ListNode* temp = answer;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            
            temp->next = new ListNode(slow->val);
            temp = temp->next;
            
            fast = fast->next->next;
        }
        
        slow = slow->next;
        
        while(slow->next != NULL){
            slow = slow->next;
            temp->next = new ListNode(slow->val);
            temp = temp->next;            
        }
        
        return answer;
    }
};