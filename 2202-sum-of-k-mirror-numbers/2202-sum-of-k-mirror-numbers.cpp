class Solution {
private:
    int digits[100]; // Buffer to store digits for base-k palindrome checking

    bool isKPalindrome(long long num, int k) {
        int length = 0;
        // Extract digits in base k
        while (num > 0) {
            digits[length++] = num % k;
            num /= k;
        }
        // Check if it's a palindrome
        for (int i = 0, j = length - 1; i < j; ++i, --j) {
            if (digits[i] != digits[j]) {
                return false;
            }
        }
        return true;
    }

public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        int left = 1; // Start with 1-digit numbers
        
        while (count < n) {
            int right = left * 10;
            
            // Generate odd-length palindromes
            for (int i = left; i < right && count < n; ++i) {
                long long palindrome = i;
                int x = i / 10;
                while (x > 0) {
                    palindrome = palindrome * 10 + x % 10;
                    x /= 10;
                }
                if (isKPalindrome(palindrome, k)) {
                    sum += palindrome;
                    count++;
                }
            }
            
            // Generate even-length palindromes
            for (int i = left; i < right && count < n; ++i) {
                long long palindrome = i;
                int x = i;
                while (x > 0) {
                    palindrome = palindrome * 10 + x % 10;
                    x /= 10;
                }
                if (isKPalindrome(palindrome, k)) {
                    sum += palindrome;
                    count++;
                }
            }
            
            left = right; // Move to next digit range
        }
        
        return sum;
    }
};