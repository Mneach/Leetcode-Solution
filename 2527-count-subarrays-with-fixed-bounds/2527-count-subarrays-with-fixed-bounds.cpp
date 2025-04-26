class Solution {
public:
    
    long long int min(long long a , long long b){
        if(a > b) return b;
        else return a;
    }
    
    long long int max(long long a, long long b){
        if(a > b) return a;
        else return b;
    }
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long int answer = 0;
        
        pair<long long int, long long int> currentMin(INT_MAX,-1);
        pair<long long int, long long int> currentMax(INT_MIN,-1);
        
        int resetIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] < minK) {
                resetIndex = i + 1;
                currentMin = {INT_MAX, -1};
                currentMax = {INT_MIN, -1};
                continue;
            }else if(nums[i] > maxK) {
                resetIndex = i + 1;
                currentMin = {INT_MAX, -1};
                currentMax = {INT_MIN, -1};
                continue;
            }
            
            currentMin.first = min(currentMin.first, nums[i]);
            currentMax.first = max(currentMax.first, nums[i]);
            
            if(currentMin.first == nums[i]) currentMin.second = i;
            if(currentMax.first == nums[i]) currentMax.second = i;
            
            if(currentMin.first == minK && currentMax.first == maxK){
                answer += 1 + min(currentMin.second, currentMax.second) - resetIndex;
            }
        }
        
        return answer;
    }
};