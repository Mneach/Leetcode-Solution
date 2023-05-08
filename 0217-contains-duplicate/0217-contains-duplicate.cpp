class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;

        for(auto i : nums){
            map[i]++;
        }

        bool checkAnswer = false;

        for(auto currentMap : map){
            if(currentMap.second >= 2) checkAnswer = true;
        }

        return checkAnswer;
    }
};