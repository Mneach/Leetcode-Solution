class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int answer = 0;        
        while (low <= high) {
            string number = to_string(low);
            low++;
            if (number.length() % 2 == 1) continue;

            int total = 0;
            for (int i = 0; i < number.length(); i++) {
                int x = number[i] - '0';
                if (i >= number.length() / 2) {
                    total -= x;
                } else {
                    total += x; 
                }
            }
            
            if (total == 0) {
                answer++;
            }
        }

        return answer;
    }
};