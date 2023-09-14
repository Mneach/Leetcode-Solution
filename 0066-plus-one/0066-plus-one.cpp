class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        if(digits[n - 1] == 9){
            if(n == 1){
                digits[0] = 1;
                digits.push_back(0);
            }else{
                int temp = n - 1;
                
                digits[temp]++;
                
                while(temp > 0 && digits[temp] == 10){
                    digits[temp] = 0;
                    digits[temp - 1]++;
                    temp--;
                }
                
                if(digits[temp] == 10){
                    auto first = digits.begin();
                    digits[0] = 0;
                    digits.insert(first, 1);
                }
            }
        }else{
            digits[n - 1] += 1;
        }
        
        return digits;
    }
};