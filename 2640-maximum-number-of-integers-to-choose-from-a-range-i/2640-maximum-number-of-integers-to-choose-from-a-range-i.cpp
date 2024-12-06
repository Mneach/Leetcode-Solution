class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_map<int,int> bucket;

        for (auto number : banned) {
            bucket[number]++;
        }

        int answer = 0;
        int left = 1;
        int total = 0;
        int take = 0;

        for (int i = 1; i <= n; i++) {
            if (bucket[i] > 0) continue;
            total += i;
            take++;

            while (total > maxSum && left <= i) {
                if (bucket[left] == 0) {
                    total -= left;
                    take--;
                }
                left++;
            }

            answer = max(answer, take);
        }

        return answer;
    }
};