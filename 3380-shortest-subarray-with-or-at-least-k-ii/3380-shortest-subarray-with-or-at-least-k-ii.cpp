class Solution {
public:

    void updateBits(vector<int> &bits, int currentNumber, bool isPlus){
        int add = isPlus == true ? 1 : -1;

        for(int i = 0; i < bits.size(); i++){
            if((currentNumber >> i) & 1){
                // to check if current number is 1
                bits[i] += add;
            }
        }
    }

    int convertBitToNum(vector<int> bits){
        int result = 0;
        for(int i = 0; i < bits.size(); i++){
            if(bits[i] > 0){
                result |= (1 << i);
            }
        }

        return result;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int size = nums.size();
        int currentResult = 0;
        int left = 0;
        int answer = INT_MAX;
        vector<int> bits(32, 0);
        
        for(int i = 0; i < nums.size(); i++){
            updateBits(bits, nums[i], true);

            currentResult = convertBitToNum(bits);

            while(currentResult >= k && left <= i){
                answer = min(answer, (i - left) + 1);
                updateBits(bits, nums[left], false);
                currentResult = convertBitToNum(bits);
                left++;
            }
        }

        currentResult = convertBitToNum(bits);
        
        while(currentResult >= k && left < size){
            answer = min(answer, size - left);
            updateBits(bits, nums[left], false);
            currentResult = convertBitToNum(bits);
            left++;
        }

        if(answer == INT_MAX) return -1;

        return answer;
    }
};

/*

# Intuition
1. if the current result >= k, try to shrink the window
2. otherwise just increase the window until current result >= k

Time complexity : 
O(N * 2) -> because we are using sliding window

Memory Complexity :
O(1) -> no need additional memory, just need to save current result in int variable

00001
00010
10000
01101

11111
00010
*/
