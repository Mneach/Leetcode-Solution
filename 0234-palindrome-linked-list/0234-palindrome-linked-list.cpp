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
    bool isPalindrome(ListNode* head) {
        
        
        vector<int> arr;
        
        ListNode* curr = head;
        
        while(curr){
            arr.push_back(curr->val);
            curr = curr -> next;
        }
        
        int left = 0;
        int right = arr.size() - 1;
        
        bool answer = true;
        
        while(left <= right){
            if(arr[left] != arr[right]){
                answer = false;
                break;
            }
            left++;
            right--;
        }
        
        return answer;
    }
};