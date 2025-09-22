/*

How to solve the problem 

# Using Two Pointer 
1. initialize the left pointer and right pointer
2. left = 0 and right = 0
3. Loop from the first index of chars array until last index of chars array
4. If the chars[right] == chars[right + 1]
   - increase count variable by  1
3. else
   - count how many digit that we have
   - loop from left pointer + total digit until left pointer + 1
     - divide the count by 10 to get the digit
     - nums[currentIndex] = digit
     - currentIndex--;
   - count = 0
   - add answer by current digit value
4. return the answer

Time Complexity : O(N + M)
N -> size of chars array
M -> maximum digit from count variable value

Memory Complexity : O(1)


*/

class Solution {
private:
    int countDigit(int number) {
        int result = 0;

        while (number > 0) {
            number /= 10;
            result++;
        }

        return result;
    }
public:
    int compress(vector<char>& chars) {
        int count = 1;
        int left = 0;
        int right = 0;

        while (right < chars.size() - 1) {
            if (chars[right] == chars[right + 1]) {
                count++;
            } else {
                if (count > 1) {
                    char currentChar = chars[right];
                    chars[left] = currentChar;

                    int totalDigit = countDigit(count);
                    int currentIndex = left + totalDigit;
                    while (currentIndex > left) {
                        // take the digit
                        int digit = count % 10;
                        chars[currentIndex] = digit + '0';
                        currentIndex--;
                        count /= 10;
                    }

                    left = left + totalDigit + 1;
                } else if (count <= 1) {
                    char currentChar = chars[right];
                    chars[left] = currentChar;
                    left++;
                } 

                count = 1;
            }

            right++;
        }

        if (count <= 1) {
            char currentChar = chars[chars.size() - 1];
            chars[left] = currentChar;
            left++;
        } else {
            char currentChar = chars[chars.size() - 1];
            chars[left] = currentChar;

            int totalDigit = countDigit(count);
            int currentIndex = left + totalDigit;
            while (currentIndex > left) {
                // take the digit
                int digit = count % 10;
                chars[currentIndex] = digit + '0';
                currentIndex--;
                count /= 10;
            }
            
            left = left + totalDigit + 1;
        }

        return left;
    }
};