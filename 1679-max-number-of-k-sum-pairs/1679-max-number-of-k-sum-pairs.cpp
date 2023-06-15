class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        int answer = 0;
        for(int i = 0; i < nums.size(); i++){
            int needed = k - nums[i];
            
            if(map[nums[i]] && map[nums[i]] > 0){
                answer++;
                map[nums[i]]--;
            }else{
                map[needed]++;
            }
        }
        
        return answer;
    }
};