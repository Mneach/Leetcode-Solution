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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* slow = NULL;
        ListNode* fast = head;
        bool skip = false;

        while (fast != NULL) {

            if (fast -> val == val) {
                skip = true;
            } else {
                skip = false;
            }

            if (skip == false) {
                if (slow == NULL) {
                    head = fast;
                    slow = fast;
                    cout << slow -> val << "->";
                } else {
                    slow -> next = fast;
                    slow = slow -> next;
                    cout << slow -> val << "->";
                }
            }

            fast = fast -> next;
        }

        if (slow == NULL) return NULL;

        if (slow -> next != NULL && slow -> next -> val == val) slow -> next = NULL;
        return head;
    }
};