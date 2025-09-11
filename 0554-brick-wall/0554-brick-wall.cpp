/*

How to solve the problem :

# Using hashtable

1. we will sum the number in every row and put that into the hash table
2. to know the answer, we need to find, the minimum value in that hash table

Time Complexity : O(N * M) -> O(N ^ 2)
N -> total row of array wall
M -> total col of array wall

Memory complexity : O(N * M) -> O(N ^ 2)
N -> total row of array wall
M -> total col of array wall

*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,long long> bucket;
        int totalRow = wall.size();

        for (int i = 0; i < wall.size(); i++) {
            long long temp = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                temp += wall[i][j];
                bucket[temp]++;
            }
        }

        int answer = totalRow;

        for (auto data : bucket) {
            int key = data.first;
            int value = data.second;

            answer = min(answer, totalRow - value);
        }

        return answer;
    }
};