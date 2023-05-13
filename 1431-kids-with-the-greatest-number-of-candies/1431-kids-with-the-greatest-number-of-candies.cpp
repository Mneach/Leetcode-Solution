class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = 0;
        
        vector<bool> answer;
        for(int i = 0; i < candies.size(); i++){
            maximum = max(maximum, candies[i]);
        }
        
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= maximum) answer.push_back(true);
            else answer.push_back(false);
        }
        
        return answer;
    }
};