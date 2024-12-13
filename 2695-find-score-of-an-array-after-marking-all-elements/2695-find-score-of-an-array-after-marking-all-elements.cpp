
/*

how to solve : 

# Using min priority queue
1. insert all the elements in nums into min priority queue
   - so we will sort the data based on the num and index asc
2. to compute the answer we need to follow the problem description
   - pop the data from priority queue
   - if the current index is already visited, we can't use that data anymore, so we need to skip
   - otherwise use the data from prority_queue and mark the before and after index as visited.

Time Complexity : N log n + O(N)
N log n -> come from insert all the elements inside the nums into min priority queue
N -> loop for every data in priority queue

Memory Complexity : O(N) + M
O(N) -> to save all the data inside the priority_queue
O(M) -> need array to mark the current index as visited;

*/


struct Compare {
public:
    bool operator()(pair<int,int> &first, pair<int,int> &second){
        if (first.first == second.first) {
            return first.second > second.second;
        } else {
            return first.first > second.first;
        }
    }
};

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long answer = 0;   

        vector<bool> visited(1e5 + 2, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            pq.push({num, i});
        }

        while(pq.size() > 0) {
            auto [num, index] = pq.top();
            pq.pop();

            if (visited[index] == true) continue;

            // mark adject cell as visited
            visited[index] = true;
            visited[index + 1] = true;

            if (index > 0) {
                visited[index - 1] = true;
            }

            answer += num;
        }

        return answer;
    }
};