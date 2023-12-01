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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<int> arr;
        
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        
        ListNode *answer = new ListNode();
        ListNode *curr = answer;
        
        int target = arr.size() - n;
        
        for(int i = 0; i < arr.size(); i++){
            if(i == target) continue;
            
            ListNode *temp = new ListNode(arr[i]);
            curr->next = temp;
            curr = curr->next;
        }
        
        return answer->next;
    }
};