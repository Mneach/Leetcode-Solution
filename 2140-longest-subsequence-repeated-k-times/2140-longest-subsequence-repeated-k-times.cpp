class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        
        vector<int> bucket(26, 0);

        for (auto c : s) {
            bucket[c - 'a']++;
        }

        vector<char> candidate;

        for (int i = bucket.size() - 1; i >= 0; i--) {
            if (bucket[i] >= k) {
                candidate.push_back('a' + i);
            }
        }

        queue<string> q;

        for (auto c : candidate) {
            q.push(string(1, c));
        }

        string answer = "";
        while(q.empty() == false) {
            string current = q.front();
            q.pop();

            if (current.size() > answer.size()) {
                answer = current;
            }

            for (auto c : candidate) {
                string next = current + c;
                bool valid = false;
                int position = 0;
                int match = 0;
                
                for (auto cs : s) {

                    if (cs == next[position]) {
                        position++;

                        if (position == next.size()) {
                            position = 0;
                            match++;

                            if (match == k) {
                                valid = true;
                                break;
                            }
                        }
                    }
                }

                if (valid) {
                    q.push(next);
                }
            }
        }

        return answer;
    }
};

