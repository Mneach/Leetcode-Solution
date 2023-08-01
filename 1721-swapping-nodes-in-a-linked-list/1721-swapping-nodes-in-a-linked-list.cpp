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
        
       
       ListNode* x = nullptr;
       ListNode* y = nullptr;
        
       for(auto p = head; p != nullptr; p = p->next){
            
          y = y == nullptr ? nullptr : y = y->next; 
           
          if(--k == 0){
              x = p;
              y = head;
          }
       } 
       
        swap(x->val, y->val);
        return head;
    }
};