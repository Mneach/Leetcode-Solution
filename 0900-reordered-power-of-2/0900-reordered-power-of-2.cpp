/*

How to solve : 
1. compute all the power of 2 number that <= INT_MAX
2. put all of those numbers in the array
3. just need to check if n has a same total digit with the array[i]
   - if no, just need to move into next index
   - otherwise, we need to count the digit in that number, if the total digit from 0 - 9 is equal, that means we can reconstruct that n to become number power of 2

*/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long long current = 1;
        // number, length of num
        vector<pair<int,int>> arr;

        while (current < INT_MAX) {
            long long temp = current;
            int length = 0;
            while (temp > 0) {
                temp /= 10;
                length++;
            }

            arr.push_back({current, length});
            current *= 2;
        }

        int lengthN = 0; 
        int temp = n;

        while (temp > 0) {
            temp /= 10;
            lengthN++;
        }

        for (auto data : arr) {
            int number = data.first;
            int length = data.second;

            if (length == lengthN) {
                vector<int> tempArr(10, 0);

                int tempN = n;
                int tempNumber = number;

                while(tempN > 0) {
                    int digit = tempN % 10;
                    tempArr[digit]++;
                    tempN /= 10;
                }

                while (tempNumber > 0) {
                    int digit = tempNumber % 10;
                    tempArr[digit]--;
                    tempNumber /= 10;
                }

                bool valid = true;

                for (auto temp : tempArr) {
                    if (temp != 0) {
                        valid = false;
                    }
                }

                if (valid) return true;

            } else if (length > lengthN) {
                // we cannot reorder the n
                break;
            }
        }

        return false;
    }
};
