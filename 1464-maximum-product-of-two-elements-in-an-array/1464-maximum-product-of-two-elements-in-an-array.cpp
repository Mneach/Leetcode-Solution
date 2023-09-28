class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> arr;
        
        for(int i = 0; i < nums.size(); i++){
            arr.push(nums[i]);
        }
        
        int answer = arr.top() - 1;
        arr.pop();
        
        answer *= arr.top() - 1;
        
        return answer;
    }
};