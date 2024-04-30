class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long mask = 0;
        unordered_map<int,int> ump;
        long long answer = 0;
        
        ump[0] = 1;
        
        for(auto w : word){
            char bit = w - 'a';
            mask ^= (1 << bit);
            
            // checking for even letter
            answer += ump[mask];
            
            // checking for odd letter
            for(int i = 0; i < 10; i++){
                long long premask = mask ^ (1 << i);
                answer += ump[premask];
            }
            
            ump[mask] += 1;
        }
        
        return answer;
    }
};