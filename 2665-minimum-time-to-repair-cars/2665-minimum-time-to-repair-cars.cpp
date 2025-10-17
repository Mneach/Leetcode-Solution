
/*

# Observation
1.	A mechanic with a rank r can repair n cars in r * n2 minutes.
2.	Find the minimum time taken to repair the cars
3.	We can change n variable to become totalCarsRepaired

# Idea
1.	We need to count how many minute that we need to repair x cars
2.	How do we know if in x minutes we can repair x cars -> "in x minutes how many cars that we can repair"

# Brute Force Solution
               I
ranks = [10], cars = 10

rank = 3
minutes = 10

totalCarsRepaired = sqrt(minutes / rank)
totalCarsRepaired = 7

# Pseudocode
1.	initialize variables
   - minMinutes = 1
   - maxMinutes = get maximum rank from ranks array * cars ^ 2
   - result = maxMinutes
2. loop from the minMinutes until maxMinutes
   - check if current minutes is a valid answer
     - totalCarsRepaired = 0
     - loop for every rank in ranks
       - totalCarsRepaired += sqrt(minutes / rank)
     - totalCarsRepaired == cars
       - result = current minute
       - break
3. return the result

Time Complexity : O(N * M)
N -> size of ranks array
M -> max minutes value

Memory Complexity : O(1)


# Binary Search

# Simulation

ranks = [4,2,3,1], cars = 10

minMinutes = 13
maxMinutes = 17
minutes = 15
result = 18
 
 I
[4,2,3,1]

totalCarsRepaired = sqrt(minutes / rank)
totalCarsRepaired = 

if totalCarsRepaired >= cars
result = minutes
maxMinutes = minutes - 1 
else
minMinutes = minutes + 1

# Pseudocode
1.	initialize variables
   - minMinutes = 1
   - maxMinutes = get maximum rank from ranks array * cars ^ 2
   - result = maxMinutes
2. while minMinutes <= maxMinutes (do binary search algorithm)
   - minutes = minMinutes + (maxMinutes - minMinutes) / 2
   - check if minutes is a valid answer
     - totalCarsRepaired = 0
     - loop for every rank in ranks
       - totalCarsRepaired += sqrt(minutes / rank)
   - if totalCarsRepaired >= cars
     - result = minutes
     - maxMinutes = minutes - 1
   - else
     - minMinutes = minutes + 1

3. return the result

Time Complexity : O(N * log M)
N -> size of ranks array
M -> max minutes value

Memory Complexity : O(1)

*/

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long minMinutes = 1;
        long long maxMinutes = *max_element(ranks.begin(), ranks.end()) * 1LL * cars * cars;
        long long result = maxMinutes;

        while (minMinutes <= maxMinutes) {
            long long minutes = minMinutes + (maxMinutes - minMinutes) / 2;

            // check if minutes is a valid answer
            long long totalCarsRepaired = 0;
            for (int i = 0; i < ranks.size(); i++) {
                totalCarsRepaired += sqrt(minutes / ranks[i]);
            }

            if (totalCarsRepaired >= cars) {
                result = minutes; 
                maxMinutes = minutes - 1;
            } else {
                minMinutes = minutes + 1;
            }
        }

        return result;
    }
};