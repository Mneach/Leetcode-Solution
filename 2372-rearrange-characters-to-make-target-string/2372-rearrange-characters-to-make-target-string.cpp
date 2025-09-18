/*

How to solve the problem : 
1. Put the every character from word "balloon" into the array
2. Loop from first index of text until last index of text
3. Put the character into the array of lower letter case with size (26) 
4. Loop from 0 - 26, and check if the targetArray[i] > 0, then calculate the answer using this formula
   - formula : array[i] / targetArray[i]
   - answer = min(answer, array[i] / targetArray[i]);

Time Complexity : O(N) 
N -> size of text

Memory Complexity : O(1)
size of memory that we used in this algorithm = 26

*/

class Solution {
public:
    int rearrangeCharacters(string text, string target) {
        vector<int> targetArray(26, 0);
        vector<int> array(26, 0);
        int answer = INT_MAX;

        for (int i = 0; i < target.length(); i++) {
            int index = target[i] - 'a';
            targetArray[index]++;
        }

        for (int i =0 ; i < text.length(); i++) {
            int index = text[i] - 'a';
            array[index]++;
        }

        for (int i = 0; i < 26;  i++) {
            if (targetArray[i] > 0) {
                answer = min(answer, array[i] / targetArray[i]);
            }
        }

        return answer;
    }
};