class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<int, stack<int>> ump;
        long long int answer = 0;

        for (int i = 0; i < s.length(); i++) {

            char current = s[i];
            int find= 'z' - current;

            // cout << i << " " << current << " " << find << endl;

            if (ump[find].size() > 0) {
                int prevIndex = ump[find].top();
                ump[find].pop();

                // cout << i << " " << prevIndex << endl;

                answer += (i - prevIndex);
            } else {
                ump[current - 'a'].push(i);
            }
        }

        return answer;
    }
};