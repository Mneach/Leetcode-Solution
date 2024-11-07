class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int answer = 0;
        int maximum = *max_element(candidates.begin(), candidates.end());

        int start = 1;
        while(start <= maximum){
            int temp = 0;
            for(int i = 0; i < candidates.size(); i++){
                int number = candidates[i]; 
                if((number & start) > 0) temp++;
            }
            start *= 2;
            answer = max(answer, temp);
        }

        return answer;
    }
};

/*

Intuition : 
just need to check each bit from 2^0 until 2^32 / maximum value in the array
that idea alwasy valid because : 
1. & operation will keep the value to 1 if and only if bit-x & bit-y is equal to 1
2. if the result of & operation is zero, that mean is not valid anymore

Time Complexity : O(32 * N) + O(N) = O(N)
O(32 * N) where 32 is the maximum bit of int and N total number in nums array
O(N) -> because we need to loop from first index until last index in the array to get maximum value of that array

Memory Complexity : O(1)

*/