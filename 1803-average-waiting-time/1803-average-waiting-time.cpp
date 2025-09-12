/*

How to solve the problem : 
1. loop from the first customer until the last customer, since the customer data is already sorted by time non descreasing and if the time is equal we just need to serve the customer in the order
2. for every loop we need to do these processes
   2.1 if the current time <= arrival time
   2.2.1 set the current time to arrival time
   
   2.2 add the current time with the time that we need to prepare a customer food
   2.3 to calculate how long the customer will wait, we can use this formula (current time - arrival time) and put the result into the sum variable

3. to know the answer we will divide the sum variable by total number of customers

Time Complexity : O(N)
N -> array of customers

Memory Complexity : O(1)

*/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long sum = 0;        
        long long currentTime = 0; 

        for (auto customer : customers) {
            int arrivalTime = customer[0];
            int time = customer[1];

            if (currentTime <= arrivalTime) {
                currentTime = arrivalTime;
            }

            currentTime += time;

            sum += currentTime - arrivalTime;
        }

        return (1.0 * sum) / (1.0 * customers.size());
    }
};