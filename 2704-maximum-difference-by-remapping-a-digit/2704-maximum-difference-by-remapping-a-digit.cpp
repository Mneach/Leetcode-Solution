class Solution {
public:
    int minMaxDifference(int num) {
        string num_str = to_string(num);
        
        // Create max number by replacing first non-'9' digit with '9'
        string max_str = num_str;
        size_t first_non_nine = max_str.find_first_not_of('9');
        if (first_non_nine != string::npos) {
            char digit_to_replace = max_str[first_non_nine];
            replace(max_str.begin(), max_str.end(), digit_to_replace, '9');
        }
        
        // Create min number by replacing first digit with '0'
        string min_str = num_str;
        char first_digit = min_str[0];
        replace(min_str.begin(), min_str.end(), first_digit, '0');
        
        return stoi(max_str) - stoi(min_str);
    }
};