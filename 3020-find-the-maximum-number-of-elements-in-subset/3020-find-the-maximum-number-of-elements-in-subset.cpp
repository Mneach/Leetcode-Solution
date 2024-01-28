class Solution {
public:
    
    int maximumLength(vector<int>& nums) {
       
        map<int, int, greater<int>> mp;
        unordered_map<int,int> bucket;
        
        for(auto data : nums) mp[data]++;
        
        int answer = 1;
        for(auto data : mp){
            
            if(data.first == 1){
                int total = data.second % 2 == 0 ? data.second - 1 : data.second;
                answer = max(total, answer);
                continue;
            }
            
            int current = data.first;
            
            int temp = 1;
            while(mp[current]){
            
                int nextNumber = sqrt(current);
                if(mp[nextNumber] > 1 && pow(nextNumber, 2) == current){
                    current = nextNumber;
                    temp += 2;
                }else{
                    break;
                }
            }
            
            answer = max(answer, temp);
        }
        
        return answer;
    }
};