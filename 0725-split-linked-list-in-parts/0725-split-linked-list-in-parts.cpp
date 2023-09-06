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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> answer;
        int size = 0;
        
        for(ListNode* i = head; i != NULL; i = i -> next){
            size++;
        }
        
        if(k > size){
            for(ListNode* i = head; i != NULL; i = i -> next){
                answer.push_back(new ListNode(i->val));
            }
            
            for(int i = 0; i < k - size; i++){
                answer.push_back(NULL);
            }
        }else{
            int modulo = size % k;
            int divider = size / k;
            
            int currentIndex = 1;
            ListNode* curr = head;
            ListNode* left = new ListNode(curr -> val);
            ListNode* right = left;
            while(curr != NULL){
                
                if(currentIndex % divider == 0){
                    if(modulo > 0){
                        right -> next = new ListNode ( curr -> next -> val );
                        right = right -> next;
                        
                        curr = curr -> next;
                        modulo--;
                    }
                    answer.push_back(left);
                    if(curr -> next){
                        left = new ListNode ( curr -> next -> val);
                        right = left;
                    }
                }else{
                    if(curr -> next){
                        right -> next = new ListNode (curr -> next -> val);
                        right = right -> next;    
                    }
                }
                
                curr = curr -> next;
                currentIndex = (currentIndex % divider) + 1;
            }
        }
        
        return answer;
    }
};