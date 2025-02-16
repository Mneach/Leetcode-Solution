class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long answer = 0;
        int totalDay = pizzas.size() / 4;
        int oddDays = totalDay / 2 + totalDay % 2;
        int evenDays = totalDay / 2;

        sort(pizzas.begin(), pizzas.end(), greater<int>());

        int currentPointer = 0;
        for (int i = 0; i < totalDay; i++) {
            if (i >= oddDays) currentPointer++; 
            answer += (1LL * pizzas[currentPointer]);
            currentPointer++;
        }

        return answer;
    }
};