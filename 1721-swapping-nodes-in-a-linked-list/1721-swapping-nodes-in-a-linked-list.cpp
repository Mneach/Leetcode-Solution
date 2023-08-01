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
        
        int totalNodes = 0;
        
        ListNode* temp = head;
        while(temp != NULL){
            totalNodes++;
            temp = temp->next;
        }
        
        ListNode* x = head;
        ListNode* y = head;
        
        for(int i = 1; i < k; i++){
            x = x->next;
        }
        
        for(int i = 1; i <= totalNodes - k; i++){
           y = y->next; 
        }
        
        swap(x->val , y->val);
        return head;
    }
};