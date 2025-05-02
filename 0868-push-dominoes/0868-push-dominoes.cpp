/*

How to solve : 
# String namipulation
- Create string that will process left 
- Create String that will process right 
- combine those strings with these condition
   - if left == 'L' and right == 'L', put 'L' to the answer
   - else if left == 'R' and right == 'R', put 'R' to the answer
   - else if left == '.' and right == '.', put the '.' to the answer
   - else if left == 'L' and right == '.', put the 'L' to the answer
   - else if left == '.' and right == 'R', put the 'R' to the answer
   - else compare total L and R, compute balance dominoes

The idea to compute balance domnioes
- if the total compare is odd, first half should be 'R', middle should be '.', second half should be 'L'
- if the total compare is even, first half should be 'R' and second half should be 'L'

Example : 
dominoes = ".L.R...LR..L.."

left =     "LL.RLLLLRLLL.."
right =    ".L.RRRRLRRRL.."
combine =. "LL.RR.LLRRLL.."

Time Complexity : O(N)
Where N -> length of the dominoes

Memory Complexity : O(N)
Where N -> length of the dominoes

*/


class Solution {
public:
    string pushDominoes(string dominoes) {
        string answer = dominoes;
        string left = dominoes;
        string right = dominoes;
        int size = dominoes.size();

        char lastChar = ' ';
        for (int i = size - 1; i >= 0; i--) {
            char domino = dominoes[i];

            if (domino == '.' && lastChar == 'L') {
                left[i] = 'L';
            }

            lastChar = left[i];
        }

        for (int i = 0; i < size; i++) {
            char domino = dominoes[i];

            if (domino == '.' && lastChar == 'R') {
                right[i] = 'R';
            }

            lastChar = right[i];
        }

        for (int i = 0; i < size; i++) {
            if (left[i] == 'L' && right[i] == 'R') {
                // compute how many different character
                int total = 0;
                while (i < size && left[i] == 'L' && right[i] == 'R') {
                    total++;
                    i++;
                }

                if (total % 2 == 1) {
                    int currentIndex = i - total;
                    int mid = i - ((total / 2) + 1);
                    while (currentIndex < mid) {
                        answer[currentIndex] = 'R';
                        currentIndex++;
                    }

                    answer[mid] = '.';
                    
                    currentIndex = mid + 1;
                    while (currentIndex < i) {
                        answer[currentIndex] = 'L';
                        currentIndex++;
                    }
                } else {
                    int currentIndex = i - total;
                    int mid = i - (total / 2);
                    while (currentIndex < mid) {
                        answer[currentIndex] = 'R';
                        currentIndex++;
                    }

                    while (currentIndex < i) {
                        answer[currentIndex] = 'L';
                        currentIndex++;
                    }
                }
                i -= 1;
            } else if (left[i] == 'L') {
                answer[i] = left[i];
            } else if (right[i] == 'R') {
                answer[i] = right[i];
            } else {
                answer[i] = left[i];
            }
        }

        return answer;
    }
};