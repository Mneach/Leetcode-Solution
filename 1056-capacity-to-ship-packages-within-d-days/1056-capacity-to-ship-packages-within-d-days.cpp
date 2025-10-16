/*


# Brute Force Solution

# Simulation

# First Simulation
weights = [3,2,2,4,1,4], days = 3
capacityPerDay = 2

           I
[3,2,2,4,1,4]
total day = 2 + 1 + 1 + 2 + 1 + 2 = 9


# Second Simulation
weights = [3,2,2,4,1,4], days = 3
capacityPerDay = 4
total weight = 8

       I
[3,2,2,4,1,4]

day 1 = 3
day 2 = 2 2
day 3 = 4
day 4 = 1
day 5 = 4


# Third Simulation
weights = [3,2,2,4,1,4], days = 3
capacityPerDay = 100
 
         I
[3,2,2,4,1,4]

day 1 = 3 2
day 2 = 2 4
day 3 = 1 4

# Pseudocode
1. initialize variables
   - minimumCapacityPerDay = maximum weight in weights array
   - maximumCapacityPerDay = sum all of the numbers in weights array
   - result = 0
2. loop from minimumCapacityPerDay until maximumCapacityPerDay
   - check if the currentCapacityPerDay is enough to ship all of the packages
     - total day = 1
     - total weight = 0
     - loop for weight in weights array
       - total weight += weight
       - if totalWeight > currentCapacity
         - reset the totalWeight = weight  
         - add total day by 1 
   - if total day <= days
     - result = min(result, currentCapacityPerDay)
3. return the result

Time Complexity : O(N * M)
N -> size of weights array
M -> maximumCapacityPerDay - minimumCapacityPerDay

Memory Complexity : O(1)

# Using Binary Search


# Simulation
weights = [3,2,2,4,1,4], days = 3
minimumCapacityPerDay = 4
maximumCapacityPerDay = 9
capacityPerDay = 6
 
 
[3,2,2,4,1,4]

day 1 = 3 2
day 2 = 2 4
day 3 = 1 4

# Pseudocode
1. initialize variables
   - minimumCapacityPerDay = maximum weight in weights array
   - maximumCapacityPerDay = sum all of the numbers in weights array
   - result = 0
2. while minimumCapacityPerDay <= maximumCapacityPerDay (binary search algorithm)
   - currentCapacityPerDay = minimumCapacityPerDay + (maximumCapacityPerDay - minimumCapacityPerDay) / 2
   - check if the currentCapacityPerDay is enough to ship all of the packages
     - total day = 1
     - total weight = 0
     - loop for weight in weights array
       - total weight += weight
       - if totalWeight > currentCapacity
         - reset the totalWeight = weight  
         - add total day by 1 
   - if total day <= days
     - result = min(result, currentCapacityPerDay)
     - maximumCapacityPerDay = currentCapacityPerDay - 1
   - else
     - minimumCapacityPerDay = currentCapacityPerDay + 1
3. return the result

Time Complexity : O(N * log M)
N -> size of weights array
M -> maximumCapacityPerDay - minimumCapacityPerDay

Memory Complexity : O(1)


*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minimumCapacityPerDay = 0;
        int maximumCapacityPerDay = 0;
        int result = INT_MAX;

        for (auto weight : weights) {
            minimumCapacityPerDay = max(minimumCapacityPerDay, weight);
            maximumCapacityPerDay += weight;
        }

        while (minimumCapacityPerDay <= maximumCapacityPerDay) {
            int currentCapacityPerDay = minimumCapacityPerDay + (maximumCapacityPerDay - minimumCapacityPerDay) / 2;

            // check if the currentCapacityPerDay is enough to ship all of the packages
            int totalDay = 1;
            int totalWeight = 0;

            for (int i = 0; i < weights.size(); i++) {
                totalWeight += weights[i];

                if (totalWeight > currentCapacityPerDay) {
                    totalWeight = weights[i];
                    totalDay++;
                }
            }

            if (totalDay <= days) {
                result = min(result, currentCapacityPerDay);
                maximumCapacityPerDay = currentCapacityPerDay - 1;
            } else {
                minimumCapacityPerDay = currentCapacityPerDay + 1;
            }
        }

        return result;
    }
};