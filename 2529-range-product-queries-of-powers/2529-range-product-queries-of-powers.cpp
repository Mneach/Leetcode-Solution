class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long> numbers;
        vector<int> answer;

        int mod = 1e9 + 7;
        for (int i = 0; i < 32; i++) {
            if (((n >> i) & 1) == 1) {
                // cout << i << endl;
                int temp = pow(2, i); 
                if (numbers.size() == 0) {
                    numbers.push_back(temp);
                } else {
                    // long long result = ((temp % mod) * (numbers[numbers.size() - 1] % mod)) % mod;
                    numbers.push_back(temp);
                }
            }
        }

        // for (auto number : numbers) {
        //     cout << number << " ";
        // }

        for (auto query : queries) {
            int start = query[0];
            int end = query[1];

            // if (start == 0) {
            //     answer.push_back(numbers[end]);
            // } else {
            //     int left = numbers[start - 1];
            //     int right = numbers[end];
            //     long result = right / left;
            //     answer.push_back(result);
            // }
            int temp = 1;
            while (start <= end) {
                temp = (temp * numbers[start]) % mod;
                start++;
            }
            answer.push_back(temp);
        }

        return answer;
    }
};