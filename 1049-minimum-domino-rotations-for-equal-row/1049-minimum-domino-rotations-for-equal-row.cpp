/*

Intuition : 
1. minimum number that have same value should be equal to the lenght of array, othwerise we cannot find the answer, so return -1
2. we just need to looping from the tops or bottom array, because the result will be same even tought we try to find the answer in the bottom array or tops array
3. to find the minimum rotation we can use this formula
   - lets say top rotation = 3 and length of the array = 10
   - total rotation if we choose bottom array should be equal = 7

How to solve : 
1. count how many x number appear
2. for every number that appear >= length of array, we will process that number
3. in every process if the current number is not equal to the number that we process, we can swap that index

Time complexity : O(N)
where N -> length of the array

Memory complexity : O(N)
where N -> length of the array

*/

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int answer = -1;
        vector<int> bucket(7, 0);

        for (auto num : tops) {
            bucket[num]++;
        }
        
        for (auto num : bottoms) {
            bucket[num]++;
        }

        int threshold = tops.size();

        for (int i = 1; i < bucket.size(); i++) {
            if (bucket[i] >= threshold) {
                vector<int> temp = tops;

                bool valid = true;
                int topRotation = 0;
                int totalSameNumber = 0;
                for (int j = 0; j < temp.size(); j++) {
                    if (temp[j] != i) {
                        if (bottoms[j] != i) {
                            valid = false;
                            break;
                        }
                        // swap the value 
                        temp[j] = bottoms[j];
                        topRotation++;
                    } else if (tops[j] == bottoms[j]) {
                        totalSameNumber++;
                    }
                }

                if (valid) {
                    // tops.size() - totalRotation should represent if we choose bottom array in the process
                    int bottomRotation = tops.size() - totalSameNumber - topRotation;
                    answer = min(topRotation, bottomRotation);
                }
            }
        }

        return answer;
    }
};