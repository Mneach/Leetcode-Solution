class Solution {
public:
    int integerBreak(int n) {
        vector<int> bucket(n + 1, 1);

        for(int i = 3; i <= n; i++){
            int answer = 0;

            for(int j = 1; j <= i / 2; j++){
                int reminder = i - j;
                int left = max(j, bucket[j]);
                int right = max(reminder, bucket[reminder]);

                answer = max(answer, right * left);
            }

            bucket[i] = answer;
        }

        // for(int i = 0; i < bucket.size(); i++){
        //     cout << i << " " << bucket[i] << endl;
        // }

        return bucket[n];
    }
};