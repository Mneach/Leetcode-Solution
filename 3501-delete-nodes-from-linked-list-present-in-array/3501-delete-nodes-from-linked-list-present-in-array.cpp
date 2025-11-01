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
        unordered_map<int,int> hashMap;

        for (auto number : nums) {
            hashMap[number]++;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            if (hashMap[curr -> val] > 0) {
                // should delete the data
                if (curr == head) {
                    ListNode* temp = head -> next;
                    // delete(head);

                    curr = head = temp;
                    prev = NULL;
                } else if (curr -> next == NULL) {
                    prev -> next = NULL;
                    // delete(curr);

                    curr = NULL;
                } else {
                   ListNode* nextNode = curr -> next; 
                   prev -> next = nextNode;

                //    delete(curr);
                   curr = nextNode;
                }
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }

        return head;
    }
};