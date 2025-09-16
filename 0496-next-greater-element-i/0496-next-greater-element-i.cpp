/*

How to solve the problem : 

# Using brute force solution
1. loop for every number in nums1 array to construct the answer
2. for every number in nums1 array, you need to do this
   - find the nums[i] in nums2 array, after that find the next greater element of nums[i]
   - if there is no greater element of nums[i], we will use -1 as the answer

Time Complexity : O (N * M)
N -> size of nums1 array
M -> size of nums2 array

Memory Complexity : O(1)

What makes the algorithm run slower ? 
1. because we need to find the number nums[i] in nums2 array and the next greater element of that number

How to improve the solution ?
1. need to find the better way to find the next greater element
2. need to find the better way to find the nums[i] from nums1 array in nums2 array

# Using Hashtable + Stack
1. We will use hashtable to map the nums[i] with the next greater element, so to know the answer of nums[i] we can get O(1) time complexity
2. To construct the next greater element we will use stack data structure to save the next greater element
3. To constcut the next greater element we need to do these steps
   - we will start from the end of index of nums2 array
   - if the stacks is empty we just need to return -1, that means there is no first greater element for that index, put the number and the first greater elemnt into hashtable
   - if the stacks is not empty, we need to check if the value of top of the stack is more than current value, then put the value from top of the stack into hashtable
   - if the stacks is not empty and the value of top of the stack is less than the current value, we need to pop that value until the top of the stack value is >= current number
4. To construct the answer, we need to loop for every number in nums1 array. After that we need to lookup into the hashtable to get the value

Time Complexity : O(N + (M + K))
N -> size of the nums1 array
M -> size of the nums2 array
K -> size of the stactks

N -> to get the answer from hashtable for every number in nums1 array
M + K -> is for construct the first greater element and answer in hashtable

Memory Complexity : O(P + K)
P -> size of hashtable
K -> size of stacks
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_map<int,int> bucket;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            int number = nums2[i];

            while (st.size() > 0 && st.top() < number) {
                st.pop();
            }

            if (st.size() == 0) {
                bucket[number] = -1;
            } else {
                bucket[number] = st.top();
            }
            
            st.push(number);
        }

        for (int i = 0; i < nums1.size(); i++) {
            answer.push_back(bucket[nums1[i]]);
        }

        return answer;
    }
};