class Solution {
public:
    string reorganizeString(string s) {
        vector<int> bucket(26, 0);

        for (auto c : s) {
            int ascii = c - 'a';
            bucket[ascii]++;
        }

        // find the most frequent character
        int currentMax = -1;
        char character;
        for (int i = 0; i < 26; i++) {
            if (bucket[i] > 0 && bucket[i] > currentMax) {
                currentMax = bucket[i];
                character = i + 'a'; 
            }
        }
        
        // check if we have valid condition
        int half = s.size() % 2 == 0 ? s.size() / 2 : (s.size() / 2) + 1;
        if (currentMax > half) return "";

        // fill the even index first;
        vector<char> result(s.size());
        int index = 0;
        while (bucket[character - 'a'] > 0) {
            result[index] = character;
            bucket[character - 'a']--;
            index += 2;
        }

        // fill empty index
        for (int i = 0; i < bucket.size(); i++) {
            while (bucket[i] > 0) {
                if (index >= s.size()) {
                    index = 1;
                }
                result[index] = i + 'a';
                index += 2;
                bucket[i]--;
            }
        }

        string answer = "";
        for (auto c : result) answer += c;

        return answer;
    }
};