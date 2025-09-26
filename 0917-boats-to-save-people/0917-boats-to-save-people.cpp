/*

How to solve the problem 

# Using sort and two pointer 
1. sort the people asc
2. initialize two pointer (left = 0 and right = people.size() - 1)
3. loop while left <= right
   - if people[left] + people[right] <= limit
     - increase the answer value by 1
     - increaes left pointer by 1
     - decreaes the right pointer by 1
   - else 
     - increase the answer value by 1
     - decrease the right pointer by 1

Time Complexity : (N log N + N)
N -> size of people
N log N -> sort algorithm
N -> to get the answer

Memory Compelxity : O(1)

*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int answer = 0;
        int left = 0;
        int right = people.size() - 1;

        sort(people.begin(), people.end());

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                answer++;
                left++;
                right--;
            } else {
                answer++;
                right--;
            }
        }

        return answer;
    }
};