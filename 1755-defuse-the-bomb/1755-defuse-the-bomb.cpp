class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> answer(code.size(), 0);
        int currentResult = 0;
        
        if(k > 0){
            int left = 1;
            int right = 1;
            currentResult = 0;

            while(k > 0){
                currentResult += code[right];
                right = (right + 1) % code.size();
                k--;
            }

            cout << left << " " << right << endl;

            for(int i = 0; i < code.size(); i++){
                answer[i] = currentResult;
                currentResult -= code[left];
                currentResult += code[right];

                left = (left + 1) % code.size();
                right = (right + 1) % code.size();
            }
            
        }else if(k < 0){
            int left = code.size() + k;
            int right = left;
            currentResult = 0;

            while(k < 0){
                currentResult += code[right];
                right = (right + 1) % code.size();
                k++;
            }

            for(int i = 0; i < code.size(); i++){
                answer[i] = currentResult;
                currentResult -= code[left];
                currentResult += code[right];

                left = (left + 1) % code.size();
                right = (right + 1) % code.size();
            } 
        }

        return answer;
    }
};


/*

Intuition to solve problem
- if k > 0
  - we will start to compute from currentIndex + 1
  - we need to check if currentIndex >= nums.size()
    - make currentIndex = 0
- if k = 0 -> just fill the answer with 0
- if k < 0
  - we will start to compute from currentIndex - 1
  - we need to check if the currentIndex - 1 < 0
    - make currentIndex = nums.size() - 1

# Implementation 1 (two-pointer technique)
1. left will start from currentIndex - 1 | currentIndex + 1
2. move rightPointer from left until left - k | left + k
3. try to move left pointer until end of nums elements

Time Complexity
O(n) -> where n is nums.size()

Memory Compelxity 
O(n) -> where n is nums.size()

*/