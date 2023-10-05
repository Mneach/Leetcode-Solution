class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int minimum = nums.size() / 3;
        
        unordered_map<int,int> arr;
        
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
        }
        
        vector<int> answer;
        for(auto data : arr){
            if(data.second > minimum){
                answer.push_back(data.first);
            }
        }
        
        return answer;
    }
};