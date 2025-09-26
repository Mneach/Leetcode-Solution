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

# What makes the algorithm slowly ? 
1. Because we need to sort the people using merge sort algorithm which take N log n time complexity

# How to improve the solution ? 
1. We can use counting sort, since the maximum value in people array == limit

# Counting Sort + Two Pointer Technique
1. Get the maximum element in the people array
2. Create vector with size == maximum element, lets called it count
3. Put all of element in people array to the array count (count[people[i]]++)
4. Try to skip the count with value 0
5. do counting sort
6. initialize two pointer (left = 0 and right = people.size() - 1)
7. loop while left <= right
   - if people[left] + people[right] <= limit
     - increase the answer value by 1
     - increaes left pointer by 1
     - decreaes the right pointer by 1
   - else 
     - increase the answer value by 1
     - decrease the right pointer by 1

Time Complexity : O(N)
N -> size of people array

Memory Complexity : O(M)
M -> size of count array

*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int maximumElement = *max_element(people.begin(), people.end());
        vector<int> count(maximumElement + 1, 0);

        for (int i = 0; i < people.size(); i++) {
            count[people[i]]++;
        }

        // counting sort and skip the count with value 0
        int peopleIndex = 0;
        int countIndex = 0;

        while (peopleIndex < people.size()) {
            
            // skip count with value 0
            while (countIndex < count.size() && count[countIndex] == 0) {
                countIndex++;
            }

            // counting sort
            // we will sort the data by putting the current value into the people array
            while (count[countIndex] > 0) {
                people[peopleIndex] = countIndex;
                count[countIndex]--;
                peopleIndex++;
            }
        }


        int answer = 0;
        int left = 0;
        int right = people.size() - 1;

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