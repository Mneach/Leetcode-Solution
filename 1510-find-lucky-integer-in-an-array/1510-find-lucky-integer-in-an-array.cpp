class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> bucket;

        for (auto num : arr) {
            bucket[num]++;
        }

        int answer = -1;
        for (auto data : bucket) {
            int key = data.first;
            int value = data.second;

            if (key == value) {
                answer = max(answer, key);
            }
        }

        return answer;
    }
};