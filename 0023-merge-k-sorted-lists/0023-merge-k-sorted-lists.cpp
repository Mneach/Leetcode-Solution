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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) return NULL;
        
        vector<int> arr;
        
        for(int i = 0; i < lists.size(); i++){
            
           ListNode* curr = lists[i];
            
            while(curr != NULL){
                arr.push_back(curr->val);
                curr = curr->next;
            }
        }
        
        if(arr.size() == 0) return NULL;
        
        sort(arr.begin(), arr.end());
        
        ListNode* answer = new ListNode(arr[0]);
        ListNode* curr = answer;
        
        for(int i = 1; i < arr.size(); i++){
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        
        
        return answer;
    }
};