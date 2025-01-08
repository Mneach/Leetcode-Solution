class Solution {
public:

    bool isValid(string s, string find) {

        if (s.length() < find.length()) return false;

        // check prefix
        for (int i = 0; i < find.length(); i++) {
            if(s[i] != find[i]) return false;
        }

        // check suffix
        int index = 0;
        for (int i = s.length() - find.length(); i < s.length(); i++){
            if (s[i] != find[index]) return false;
            index++;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int answer = 0;
        for (int i = 0; i < words.size(); i++) {

            for (int j = i + 1; j < words.size(); j++) {
                if(isValid(words[j], words[i])) {
                    answer++;
                }
            }
        }

        return answer;
    }
};