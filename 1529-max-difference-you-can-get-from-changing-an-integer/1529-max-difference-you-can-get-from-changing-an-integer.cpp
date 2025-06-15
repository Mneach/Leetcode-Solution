class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        return getMax(s) - getMin(s);
    }

private:
    int getMax(string s) {
        // Find first non-9 digit and replace all instances with 9
        for (char& c : s) {
            if (c != '9') {
                char target = c;
                for (char& d : s) {
                    if (d == target) d = '9';
                }
                break;
            }
        }
        return stoi(s);
    }

    int getMin(string s) {
        // For first digit: replace with 1 if not already 1
        // For other digits: replace with 0 if different from first digit
        char first = s[0];
        
        if (first != '1') {
            // Replace all instances of first digit with '1'
            for (char& c : s) {
                if (c == first) c = '1';
            }
        } else {
            // Find first digit > '1' and replace all instances with '0'
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != first) {
                    char target = s[i];
                    for (char& c : s) {
                        if (c == target) c = '0';
                    }
                    break;
                }
            }
        }
        
        return stoi(s);
    }
};