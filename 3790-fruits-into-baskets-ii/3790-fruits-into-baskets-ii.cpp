class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int answer = 0;
        for (auto basket : baskets) {
            int index = -1;
            int result = INT_MIN;
            for (int i = 0; i < fruits.size(); i++) {
                int data = fruits[i];

                if (data != INT_MIN && data <= basket) {
                    index = i;
                    result = data;
                    break;
                }
                
            }

            if (result == INT_MIN) answer++;
            else fruits[index] = INT_MIN;
        }

        return answer;
    }
};