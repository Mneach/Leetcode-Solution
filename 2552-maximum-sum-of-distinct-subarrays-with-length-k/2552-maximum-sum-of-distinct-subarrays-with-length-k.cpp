class Solution {
public:

    long long max(long long a, long long b){
        if(a > b) return a;
        else return b;
    }

    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<long long int,int> ump;
        long long int answer = 0;
        long long int sum = 0;

        int tempK = k;
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            tempK--;
            ump[nums[right]]++;
            sum += nums[right];

            if(ump[nums[right]] > 1){
                // move left pointer to the right pointer
                while(left < right && ump[nums[right]] != 1) {
                    sum -= nums[left];
                    ump[nums[left]]--;
                    left++;
                    tempK++;
                }
                tempK = k - ((right - left) + 1);
            }

            if(tempK <= 0){
                answer = max(answer, sum);
                sum -= nums[left];
                ump[nums[left]]--;
                left++;
            }
        }

        return answer;
    }
};

/*

Intuition : 
- Need to sum nums of elements from nums[i] until nums[i + k]
- to check whether there is duplicate number inside (index[i] until index[i + k]) we can use these solutions
  - loop from index[i] until index[i + 1] and store the number in a container
  - using hashmap to check whether there is a duplicate number
    - every process we need to do this
      - decrement value on hashMap[nums[i]] 
      - increment value ono hashMap[nums[i + k]]
- if there is a duplicate number inside (index[i] until index[i + k])
  - move left pointer to the right pointer
    - every process we need to decrement nums[left]
  - reset the sum value to become nums[right]


Implementation : Using two pointer technique
- start left from 0 and right from 0 + k

Time Complexity : 
O(n - k) -> O(n) -> where n is number of elements in array nums

Memory Complexity : 
O(k) -> where k is total distinct number that we can save in hashmap

*/