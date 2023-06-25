class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int answer = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                string x = to_string(nums[i]);
                string y = to_string(nums[j]);
                
                int firstDigit = x[0] - '0';
                int lastDigit = y[y.length() - 1] - '0';
                
                if(gcd(firstDigit, lastDigit) == 1) answer++; 
                    
            }
        }
        
        return answer;
    }
};