class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
       vector<int> arr(101, 0);
        
       for(int i = 0; i < nums.size(); i++){
           arr[nums[i]]++;
       } 
        
       int answer = 0;
        
       for(int i = 1; i < 101; i++){
          if(arr[i] > 0) answer++;
       }
        
       return answer;
    }
};