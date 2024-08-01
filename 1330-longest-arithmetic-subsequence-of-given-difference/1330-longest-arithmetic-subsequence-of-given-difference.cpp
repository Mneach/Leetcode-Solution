class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> ump;
        int answer = 0;

        for(int i = arr.size() - 1; i >= 0; i--){
            int number = arr[i];
            ump[number] = ump[number -(-difference)] + 1;
            answer = max(ump[number], answer);
        }

        return answer;
    }
};

/*

1. state only take or skip
   - we will take if the difference between current[i] and current[j] is equal to diff value
   - otherwise we will skip that
2. every single process we need to cache the result, so it can improve the time complexity of the algorithm
3. base case -> if the current index == arr.size() return 0;

*/