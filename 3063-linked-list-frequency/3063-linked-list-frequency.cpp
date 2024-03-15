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
    ListNode* frequenciesOfElements(ListNode* head) {
        
        
        map<int,int> mp;
        
        while(head){
            mp[head->val]++;
            head = head->next;
        }
        
        ListNode* answer = new ListNode();
        ListNode* curr = answer;
        for(auto data : mp){
            curr->next = new ListNode(data.second);
            curr = curr->next;
        }
        
        return answer->next;
    }
};