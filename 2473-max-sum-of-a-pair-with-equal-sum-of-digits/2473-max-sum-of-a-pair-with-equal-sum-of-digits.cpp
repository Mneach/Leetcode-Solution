
/*

Intuition : 
1. sum digit for every elements in nums
2. put the sum value inside the hashmap, with key = sum and value = number
3. looping for every data in hashmap, get first maximum and second maximum number
4. inside the hashmap, we can use priority queue, so we dont need to sort manually 

Time complexity : O(total diff sum) + n log n
n = number of elements in nums

Memory Complexity : O(n)
n = number of elements in nums

*/

class Solution {
public:

    int sumDigit(int number) {
        int result = 0;
        while(number > 0) {
            result += number % 10;
            number /= 10;
        } 

        return result;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> bucket;
        int answer = -1;

        for (auto num : nums) {
            int sum = sumDigit(num);
            bucket[sum].push(num);
        }

        for (auto data : bucket) {
            if (data.second.size() > 1) {
                int firstMaximum = data.second.top();
                data.second.pop();
                int secondMaximum = data.second.top();
                data.second.pop();

                answer = max(answer, firstMaximum + secondMaximum);
            }
        }

        return answer;
    }
};