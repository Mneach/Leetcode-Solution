/*

How to solve the problem : 

# Brute Force Solution
1. Loop from first index of array until last index of array
2. For every index we need to know how many this string appear in the array
3. if arr[i] appear only 1 times in an array, we can decreaes the K value
4. if the K value is 0 return arr[i]
5. if the condition is not fullfill after run that algorithm, we need to return ""

Time Complexity : O(N^2)
N -> size of arr

Memory Complexity : O(1)

# Hashtable approach
1. Construct the hashtable, so we need to loop from first index of arr until last index of arr
2. put the arr[i] into hashtable, so hashtable will have key = arr[i], value = how many arr[i] appear in the arr
3. loop from the first index of arr until last index of arr
4. for every index we need to loopkup into the hashtable with key = arr[i] (hashtable[arr[i]])
   - if the value of hashtable[arr[i]] == 1, decrease the K by 1
   - otherwise just skip

Time Complexity : O(N + N)
N -> size of array
first N -> to construct the hashtable
second N -> to get the answer

Memory Complexity : O(M)
M -> size of hashtable

*/

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> hashtable;

        for (int i = 0; i < arr.size(); i++) {
            hashtable[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (hashtable[arr[i]] == 1) {
                k--;
            }

            if (k == 0) {
                return arr[i];
            }
        }

        return "";
    }
};