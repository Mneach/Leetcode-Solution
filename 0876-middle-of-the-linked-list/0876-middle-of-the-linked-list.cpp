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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* curr = head;
        
        
        int totalIndex = 0;
        while(curr != NULL){
            totalIndex++;
            curr = curr->next;
        }
        
        totalIndex = (totalIndex / 2);
        
        for(int i = 0; i < totalIndex; i++){
            head = head->next;
        }
        
        return head;
    }
};