
/*

How to solve : 
1. loop from arr.size() - 1 until 0
2. every process we need to find the current maximum number in that index
3. replace the value of index[i] with current maximum number in that index

Time complexity : O(N)
N -> Size of array

Memory complexity : O(N)
N -> Size of array

*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> answer(arr.size(), -1);

        int maximum = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            answer[i] = maximum;
            maximum = max(maximum, arr[i]);
        }

        return answer;
    }
};