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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> answer;

        ListNode* curr = head -> next;
        ListNode* currPrev = head;

        int index = 1;
        while(curr != NULL && curr -> next){

            if(currPrev->val > curr -> val && curr -> next -> val > curr -> val){
                answer.push_back(index);
            }else if(currPrev->val < curr -> val && curr -> next -> val < curr -> val){
                answer.push_back(index);
            }
            
            currPrev = curr;
            curr = curr -> next;
            index++;
        }

        if(answer.size() < 2) return {-1, -1};

        int minDistance = INT_MAX;
        int maxDistance = answer[answer.size() - 1] - answer[0];

        for(int i = 1; i < answer.size(); i++){
            cout << answer[i] << " " ;
            minDistance = min(minDistance, answer[i] - answer[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};