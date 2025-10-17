
/*

# Observation
1.	we need to perform at most maxOperations times
2.	Take any bag of balls and divide it into two new bags with a positive number of balls.
3.	We need to minimize the penalty after the operations
4.	After do all of the operations, size of the array should become equal to the 2x from original size

# Brute Force Solution


# Simulation

minPenalty = 1
maxPenalty = 8

       I
[2,4,8,2], maxOperations = 4

penalty = 2

totalOperations = (nums[i] / penalty) - 1
totalOperations = 4

[1,1,1,1,1,1]

# Pseodecode
1.	initialize variables
   - minPenalty = 1
   - maxPenalty = maximum number in nums array
   - result = maxPenalty
2. loop from minPenalty until maxPenalty
   - check if penalty is a valid result
     - totalOperations = 0 
     - loop for every number in nums array
       - if (nums[i] % penalty) == 0
         - totalOperations += (nums[i] / penalty) - 1
       - else
         - totalOperations += (nums[i] / penalty)
     - if totalOperations == maxOperations
       - result = penalty
       - break
3. return the result

Time complexity : O(N * M)
N -> size of nums array
M -> max penalty value -> max number in nums array

Memory Complexity : O(1)

# Binary search

# Simulation
nums = [2,4,8,2], maxOperations = 4

minPenalty = 2
maxPenalty = 1
penalty = minPenalty + (maxPenalty - minPenalty) / 2
penalty = 1

result = 2

 I
[2,4,8,4]

if (nums[i] <= penalty) skip nums[i]

totalOperations = (nums[i] / penalty) - 1
totalOperations = 1 + 3 + 7 + 3 = 14

# Pseodecode
1.	initialize variables
   - minPenalty = 1
   - maxPenalty = maximum number in nums array
   - result = maxPenalty
2. while minPenalty <= maxPenalty (do binary search algorithm)
   - penalty = minPenalty + (maxPenalty - minPenalty) / 2
   - check if penalty is a valid result
     - totalOperations = 0
     - loop for every number in nums array
       - if (nums[i] % penalty) == 0
         - totalOperations += (nums[i] / penalty) - 1
       - else
         - totalOperations += (nums[i] / penalty)
   - if totalOperations <= maxOperations
     - result = penalty
     - maxPenalty = penalty - 1
   - else
     - minPenalty = penalty + 1
3. return the result

Time Complexity : O(N * log M)
N -> size of nums
M -> max number in nums array

Memory Complexity : O(1)

*/

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int minPenalty = 1;
        int maxPenalty = *max_element(nums.begin(), nums.end());
        int result = maxPenalty;

        while (minPenalty <= maxPenalty) {
            int penalty = minPenalty + (maxPenalty - minPenalty) / 2;

            // check if current penalty is a valid answer
            long long totalOperations = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= penalty) {
                    continue;
                }

                if (nums[i] % penalty == 0) {
                    totalOperations += (1LL * nums[i] / penalty) - 1;
                } else {
                    totalOperations += (1LL * nums[i] / penalty);
                }
            }

            if (totalOperations <= maxOperations) {
                result = penalty;
                maxPenalty = penalty - 1;
            } else {
                minPenalty = penalty + 1;
            }
        }

        return result;
    }
};