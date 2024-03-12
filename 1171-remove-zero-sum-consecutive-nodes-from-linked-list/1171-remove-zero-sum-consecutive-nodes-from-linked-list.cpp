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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* curr = head;
        ListNode* front = new ListNode(0, head);
        
        int prefixSum = 0;
        map<int, ListNode*> mp;
        mp[0] = front;
        
        while(curr){
            prefixSum += curr->val;
            mp[prefixSum] = curr;
            curr = curr->next;
        }
        
        prefixSum = 0;
        curr = front;
        
        while(curr){
            prefixSum += curr->val;
            curr->next = mp[prefixSum]->next;
            curr = curr->next;
        }
        
        return front->next;
    }
};