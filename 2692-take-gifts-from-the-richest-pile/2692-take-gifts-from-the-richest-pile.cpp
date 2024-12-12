class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long int> pq;

        for (auto gift : gifts) pq.push(gift);

        for (int i = 0; i < k; i++) {

            long long int top = pq.top();
            pq.pop();

            pq.push(sqrt(top));
        }

        long long answer = 0;

        while (pq.size() > 0) {
            long long top = pq.top();
            pq.pop();

            answer += top;
        }

        return answer;
    }
};