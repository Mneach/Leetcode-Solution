class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        int total_candies = n;  // Start with 1 candy per child
        int i = 1;
        
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }
            
            // Handle increasing sequence (peak)
            int peak_length = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak_length++;
                total_candies += peak_length;
                i++;
            }
            
            // Handle decreasing sequence (valley)
            int valley_length = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                valley_length++;
                total_candies += valley_length;
                i++;
            }
            
            // Subtract the overlapping minimum (we counted it twice)
            total_candies -= min(peak_length, valley_length);
        }
        
        return total_candies;
    }
};