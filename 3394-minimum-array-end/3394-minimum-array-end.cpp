class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x; // Initialize result with x
        long long mask = 1;   // Start with a mask of 1 to check each bit in x
        --n;                  // Decrement n by 1 to exclude x from the iteration

        // Iterate over each bit position
        while (n > 0) {
            // If the current bit in x is 0, set the corresponding bit in result
            if ((x & mask) == 0) {
                result |= (n & 1) * mask; // Set the bit based on the least significant bit of n
                n >>= 1;                  // Shift n to the right to prepare for the next bit
            }
            mask <<= 1;                   // Move the mask to the next bit position
        }

        return result;
    }
};
