class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        unordered_map<int,int> ump;
        
        int answer = -1;
        for(int i = 0; i < nums.size(); i++){
            int number = nums[i];
            if(number < 0 && ump[number * -1] > 0){
                answer = max(answer, number * -1);
            }else if(number > 0 && ump[number * -1] > 0){
                answer = max(answer, number);
            }
            
            ump[number]++;
        }
        
        return answer;
    }
};