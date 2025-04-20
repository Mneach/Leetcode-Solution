class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int answer = 0;
        unordered_map<int,int> bucket;

        for (auto answer : answers) {
            bucket[answer]++;
        }

        for (auto data : bucket) {
            int number = data.first;
            int total = data.second;

            if (total % (number + 1) != 0) {
                answer += ((total / (number + 1)) + 1) * (number + 1);
            } else {
                answer += (total / (number + 1)) * (number + 1);
            }
        }

        return answer;
    }
};