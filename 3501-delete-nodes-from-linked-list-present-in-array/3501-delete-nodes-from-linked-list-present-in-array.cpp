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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        vector<int> bucket;
        unordered_map<int,int> ump;

        for(auto data : nums) ump[data]++;

        ListNode* curr = head;
        while(curr != NULL){
            if(ump[curr -> val] <= 0){
                bucket.push_back(curr -> val);
            }
            curr = curr -> next;
        }

        ListNode* answer = new ListNode(bucket[0]);
        ListNode* point = answer;

        for(int i = 1; i < bucket.size(); i++){
            point -> next = new ListNode(bucket[i]);
            point = point -> next;
        }

        return answer;
    }
};