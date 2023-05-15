class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char , int> map;
        
        for(int i = 0; i < jewels.length(); i++){
            map[jewels[i]] = 1;
        }
        
        int total = 0;
        for(int i = 0; i < stones.length(); i++){
            if(map[stones[i]] == 1) total++;
        }
        
        return total;
    }
};