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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        
        ListNode* left = list1;
        ListNode* right = list1;
        
        int countA = 1;
        int countB = 0;
        
        while(countA < a){
            left = left->next;
            countA++;
        }
        
        while(countB < b){
            right = right->next;
            countB++;
        }
        
        cout << left->val << " " << right->val << endl;
        
        while(list2){
            left -> next = new ListNode(list2->val);
            list2 = list2->next;
            left = left->next;
        }
        
        while(right->next){
            left -> next = new ListNode(right->next->val);
            right = right->next;
            left = left->next;
        }

        
        return list1;
    }
};