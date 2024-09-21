class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        int currentNumber = 1;

        for(int i = 0; i < n; i++){
            answer.push_back(currentNumber);

            if(currentNumber * 10 <= n){
                currentNumber *= 10;
            }else{
                
                while(currentNumber % 10 == 9 || currentNumber >= n){
                    currentNumber /= 10;
                }

                currentNumber += 1;
            }
        }

        return answer;
    }
};

/*

# Implementation 1 (using trie)
solution link : https://leetcode.com/problems/lexicographical-numbers/submissions/1397367975?envType=daily-question&envId=2024-09-21
Time Complexity : O(n) 
- need to traverse and construct the trie from 1 until n
Memory Complexity : O(n)
- need to save from 1 until n

# Implementation 2 (using math idea)
Time Complexity : O(n)
Memory Complexity : (1)
*/