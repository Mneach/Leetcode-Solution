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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* curr = head;
        vector<int> bucket;

        while(curr != NULL){
            bucket.push_back(curr -> val);
            curr = curr -> next;
        }

        unordered_map<int,int> ump;

        ListNode* answer = new ListNode(0);
        curr = answer;

        vector<int> temp;
        for(int i = 0; i < bucket.size(); i++){
            ump[bucket[i]]++;
        }

        for(int i = 0; i < bucket.size(); i++){
            if(ump[bucket[i]] > 1) continue;

            curr -> next = new ListNode(bucket[i]);
            curr = curr -> next;
        }

        return answer -> next;
    }
};