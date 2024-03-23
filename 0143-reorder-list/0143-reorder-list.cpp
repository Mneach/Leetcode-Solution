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
    
    void printAllList(ListNode* curr){
        while(curr){
            cout << curr -> val << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
    
    void reorderList(ListNode* head) {
        
        if(head == NULL) return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* currNext = NULL;
        
        while(curr){
            currNext = curr -> next;
            
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }
        
        printAllList(head);
        printAllList(prev);
        
        ListNode* currFront = head;
        ListNode* currBack = prev;
        ListNode* temp = NULL;
        
        while(currBack -> next){
            temp = currFront -> next;
            currFront->next = currBack;
            currFront = temp;
            
            temp = currBack->next;
            currBack->next = currFront;
            currBack = temp;
        }
    }
};