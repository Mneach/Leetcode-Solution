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
    int getDecimalValue(ListNode* head) {
        int length = -1;
        int answer = 0;
        ListNode* curr = head;

        while (curr != NULL) {
            length++;
            curr = curr -> next;
        }

        curr = head;
        while(curr != NULL) {
            if (curr -> val == 1) {
                answer += pow(2, length);
            }
            curr = curr -> next;
            length--;
        }

        return answer;
    }
};