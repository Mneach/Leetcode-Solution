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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head) return NULL;
        if(left == right) return head;
        
        int counter = 1;
        
        ListNode* curr = head;
        ListNode* temp = curr; 
        while(curr && counter < left){
            if(left - 1 == counter) temp = curr;
            curr = curr -> next;
            counter++;
        }
        
        ListNode* back = curr;
        ListNode* front;
        ListNode* next = curr -> next;
        ListNode* prev = curr; 
        
        while(next != NULL && counter < right){
            curr = next;
            next = next -> next;
            curr -> next = prev;
            prev = curr;
            counter++;
        }
        
        front = curr;
        cout << temp -> val << " " << front -> val << endl;
        temp -> next = front;
        back -> next = next;
        
        if(left == 1 && next == NULL){
            return front;
        }else if(left == 1){
            return front;
        }else{
            return head;
        }
    }
};