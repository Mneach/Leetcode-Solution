class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int totalZero = 0;
        int sum = 1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) totalZero++;
            else sum *= nums[i];
        }
        
        vector<int> answer;
        cout << sum << " " << totalZero << endl;
        
        for(int i = 0; i < nums.size(); i++){
            if(totalZero == 0){
                answer.push_back(sum / nums[i]);   
            }else if(totalZero == 1){
                if(nums[i] == 0){
                    answer.push_back(sum);
                }else{
                    answer.push_back(0);
                }
            }else if(totalZero >= 2){
                answer.push_back(0);
            }
        }
        
        return answer;
    }
};