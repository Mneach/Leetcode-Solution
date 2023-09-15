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
    
    ListNode* recursive(ListNode* head){
        
        if(head){
            ListNode * next = recursive(head->next);
            
            if(next){
                if(head->val < next->val){
                    head = next;
                }else{
                    head->next = next;
                }
            }
            
            return head;
        }
        return NULL;
    }
    
    ListNode* removeNodes(ListNode* head) {
        
        return recursive(head);
    }
};