class Solution {
public:
    char kthCharacter(int k) {
        string start = "a";

        while(start.length() < k) {
            string temp = "";

            for (auto c : start) {
                char next = c;
                if (next == 'z') {
                    next = 'a';
                } else {
                    next += 1;
                }

                temp += next;
            }
            start += temp;
        }

        return start[k - 1];
    }
};