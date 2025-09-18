/*

How to solve the problem : 

# Using Sorting Algorithm
1. To know which number must be come the first number, we can compare the number using this idea
   - number 1 = 30
   - number 2 = 3
   - number 1 + number 2 > number 2 + number 1, then number 1 must be come first than number 2, otherwise number 2 must be come first than number 1
   - ex : 303 > 330, then we need to swap number 2 with number 1 position
2. Sorting the nums array using merge sort algorithm and use condition above 
3. Loop from the first index of array until the last index of array to construct the answer
   - need to transform nums[i] from number to string

edge cases :
1. what if nums only contain [0,0]
   - we should return 0

Time Complexity : O(N log n)
N -> size of nums

Memory Complexity : O(1)

*/


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), [](int first, int second) {
            string firstNumber = to_string(first);
            string secondNumber = to_string(second);

            return firstNumber + secondNumber > secondNumber + firstNumber;
        });

        string answer = "";
        for (int i = 0; i < nums.size(); i++) {
            if (answer == "" && nums[i] == 0) {
                return "0";
            }
            answer += to_string(nums[i]);
        }

        return answer;
    }
};