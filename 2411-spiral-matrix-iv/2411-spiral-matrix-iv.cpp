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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        // 0 -> top
        // 1 -> right
        // 2 -> bottom 
        // 3 -> left

        int move = 0;
        int x = 0;
        int y = 0;
        while(head != nullptr){
            int value = head -> val;

            int count = 0;
            while(count < 4){
                if((move == 0 && y - 1 < 0) || (move == 0 && y - 1 >= 0 && matrix[y - 1][x] != -1)){
                    move = 1;
                }else if((move == 1 && x + 1 >= matrix[0].size()) || (move == 1 && x + 1 < matrix[0].size() && matrix[y][x + 1] != -1)){
                    move = 2;
                }else if((move == 2 && y + 1 >= matrix.size()) || (move == 2 && y + 1 < matrix.size() && matrix[y + 1][x] != -1)){
                    move = 3;
                }else if((move == 3 && x - 1 < 0) || (move == 3 && x - 1 >= 0 && matrix[y][x - 1] != -1)){
                    move = 0;
                }else{
                    break;
                }
                
                count++;
            }

            

            // cout << y << " " << x << " " << value << " " << move << endl;
            matrix[y][x] = value;

            if(move == 0) y--;
            else if(move == 1) x++;
            else if(move == 2) y++;
            else if(move == 3) x--;

            if(count == 4) break;

            head = head -> next;
        }

        return matrix;
    }
};