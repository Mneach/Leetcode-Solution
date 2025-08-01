class Solution {
public:
    int smallestNumber(int n) {
        int answer = 0;
        int rank = 0;

        while (answer < n) {
            answer += pow(2, rank);
            rank++;
        }

        return answer;
    }
};