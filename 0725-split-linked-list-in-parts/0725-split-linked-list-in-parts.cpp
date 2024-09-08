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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<int> arr;
        
        while(head != nullptr){
            arr.push_back(head -> val);
            head = head -> next;
        }

        int divide = arr.size() / k;
        int extra = arr.size() % k;

        vector<ListNode*> answer;

        int count = 1;
        ListNode* tempHead = arr.size() == 0 ? nullptr : new ListNode(arr[0]);
        ListNode* current = tempHead;

        for(int i = 1; i < arr.size(); i++){

            if(extra == 0 && count == divide){
                answer.push_back(tempHead);
                tempHead = new ListNode(arr[i]);
                current = tempHead;
                count = 1;
            }else if(extra > 0 && count == divide + 1){
                answer.push_back(tempHead);
                tempHead = new ListNode(arr[i]);
                current = tempHead;
                extra--;
                count = 1;
            }else{
                ListNode* next = new ListNode(arr[i]);
                current -> next = next;
                current = next;
                count++;
            }
        }

        if(tempHead != nullptr){
            answer.push_back(tempHead);
        }

        while(answer.size() != k){
            answer.push_back(nullptr);
        }

        return answer;
    }
};