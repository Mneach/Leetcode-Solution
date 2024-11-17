class Solution {
public:
    long long min(long long a, long long b){
        if(a > b) return b;
        else return a;
    }

    int shortestSubarray(vector<int>& nums, int k) {
        long long answer = INT_MAX;
        long long currentSum = 0;
        
        // first -> sum at index[i]
        // second -> index
        deque<pair<long long int,int>> dq;

        for(int i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            // check if the currentSum >= k
            if(currentSum >= k){
                answer = min(answer, i + 1);
            }

            // try to shrink the window
            int prevIndex = -1;
            while(dq.size() > 0 && currentSum - dq.front().first >= k){
                prevIndex = dq.front().second;
                dq.pop_front();
            }

            // update the answer after shirnk the window
            if(prevIndex != -1){
                answer = min(answer, (i - prevIndex));
            }

            // maintain the mountain
            while(dq.size() > 0 && currentSum <= dq.back().first){
                dq.pop_back();
            }

            dq.push_back({currentSum, i});
        }

        if(answer == INT_MAX) return -1;
        else return answer;
    }
};

/*

Intuition : 
- if currentSum >= k store the current window to the answer
- try to shirnk the window, if the currentSum - deqeue.front().sum >= k
  - if we can shrink the window, we need to recalculate the answer
  - answer = min(answer, (rightIndex - leftIndex))

- try to maintain the mountain, make sure alwasy increasing
  - if the currentSum < deque.back().sum 
    - pop until currentSum > deque.back().sum

Implementation : 
- using datastructure deqeue

Time Complexity : 
O(N) -> where N is equal to number of element in nums

Memory Complexity : 
O(N) -> where N is come from array of sum

*/