class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
       
        int answer = 0;
        unordered_map<string, int> map;
        
        for(auto number : nums) map[number]++;
        
        for(int i = 0; i < target.size(); i++){
            string first = target.substr(0, i);
            string last = target.substr(i, target.size());
            
            if(first == last){
                answer += map[first] * (map[last] - 1);
            }else{
                answer += map[first] * map[last];
            }
        }
        
        return answer;
    }
};