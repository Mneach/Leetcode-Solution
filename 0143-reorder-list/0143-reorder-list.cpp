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
    void reorderList(ListNode* head) {
        
        ListNode* curr = head;
        
        vector<int> arr;
        
        while(curr){
            arr.push_back(curr->val);
            curr = curr -> next;
        }
        
        curr = head;
        int left = -1;
        int right = arr.size();
        for(int i = 0; i < arr.size(); i++){
            int index = i;
            if(i % 2 != 0){
                right--;
                index = right;
            }else{
                left++;
                index = left;
            }
            curr->val = arr[index];
            curr = curr -> next;
        }
        
        
    }
};