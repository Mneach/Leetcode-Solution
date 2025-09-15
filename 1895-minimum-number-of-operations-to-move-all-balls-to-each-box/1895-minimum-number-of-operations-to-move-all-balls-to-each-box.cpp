/*

How to solve the problem : 

# Using Brute Force Solution
1. loop from left index until right index of the array
2. to calculate the answer at index 1, you need to loop again from left to right index of the array
   2.1 calculate the disntance between index j with index i and put that into the answer[i]

Time Complexity : O(N^2)
N -> size of the array

Memory Complexity : O(1)

What makes the algorithm run slower ? 
1. to know the answer at index 1, you need to iterate from left until right index of the array

# Using Prefix Sum 
1. we will introduce 4 variables, "left, leftResult, right, rightResult"
2. loop from left index until right index of the array, everytime we meet '1' we will compute the distance between current index with 0, we can simply just add the current index to the rightResult
3. loop from left index until right index of the array to calculate the answer at index i
   - we can use this formula to calculate the answer at index i : leftResult + rightResult 
   - update left result everytime we move the index, since the disntance will be updated by 1, formula : leftResult + left
   - update right result everytime we move the index, since the distance will be updated by 1
   formula : rightResult - right
   - if the current index is '1', we need to increase the left value by 1, and decrease the right value by 1

edge cases : 
if the current index = 0, then we just need to use directly from the right result 

Time Complexity : O(N + N)
N -> size of the boxes array
first N -> because of we precompute the right result and right index
second N -> because of we need to calculate the answer

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = 0;
        int leftResult = 0;
        int right = 0;
        int rightResult = 0;
        vector<int> answer;

        // precompute the right and right result
        for (int i = 0; i < boxes.length(); i++) {
            int ball = boxes[i] - '0';

            if (ball == 1) {
                right++;
                rightResult += i;
            }
        }

        for (int i = 0; i < boxes.length(); i++) {
            int ball = boxes[i] - '0';

            answer.push_back(leftResult + rightResult);

            if (ball == 1) {
                left += 1;
                right -= 1;
            }

            leftResult += left;
            rightResult -= right;
        }

        return answer;
    }
};