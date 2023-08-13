class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> arr;
        
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
        }
        
        for(auto data : arr){
            if(data.second == 1) return data.first;    
        }
        
        return 0;
    }
};