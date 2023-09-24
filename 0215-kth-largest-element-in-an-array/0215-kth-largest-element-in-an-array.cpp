class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        map<int,int, greater<int>> arr;
        
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
        }
        
        
        int answer = 0;
        for(auto data : arr){
            
            while(data.second > 0 && k > 0){
                k--;
                data.second--;
            }
            if(k == 0){
                answer = data.first;
                break;
            }
        }
        
        return answer;
    }
};