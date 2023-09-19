class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> arr;
        
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
        }
        
        int answer = 0;
        
        for(auto data : arr){
            
            if(data.second > 1){
                answer = data.first;
            }
        }
        
        return answer;
    }
};