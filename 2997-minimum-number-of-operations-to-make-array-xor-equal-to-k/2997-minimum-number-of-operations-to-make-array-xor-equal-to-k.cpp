class Solution {
public:
    
    string intToBinary(int number){
        string result = "";
        
        while(number > 0){
            if(number % 2 == 0){
                result += '0';
            }else{
                result += '1';
            }
            
            number /= 2;
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    int minOperations(vector<int>& nums, int k) {
        
        int result = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            result ^= nums[i];
        }
        
        string binaryK = intToBinary(k);
        string binaryResult = intToBinary(result);
        
        string temp = "";
        if(binaryK.length() < binaryResult.length()){
            
            for(int i = binaryK.length(); i < binaryResult.length(); i++){
                temp += '0';
            }
            
            binaryK.insert(0, temp);
        }else{
            for(int i = binaryResult.length(); i < binaryK.length(); i++){
                temp += '0';
            }
            
            binaryResult.insert(0, temp);
        }
        
        // compare
        int answer = 0;
        for(int i = 0; i < binaryK.length(); i++){
            if(binaryK[i] != binaryResult[i]) answer++;
        }
        
        return answer;
    }
};