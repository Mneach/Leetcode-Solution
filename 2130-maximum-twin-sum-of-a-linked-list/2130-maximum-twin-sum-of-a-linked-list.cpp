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
    
    ListNode* mid = NULL;
    int answer = 0;
    
    void backTracking(ListNode* slow, ListNode* fast){
        if(fast->next == NULL){
            mid = slow->next;
            answer = max(answer, slow->val + mid->val);
            mid = mid->next;
            return ;
        }
        backTracking(slow->next, fast->next->next);
        cout << slow->val << " " << mid->val << endl;
        answer = max(answer, slow->val + mid->val);
        mid = mid->next;
    }
    
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        backTracking(slow , fast);
        
        return answer;
    }
};