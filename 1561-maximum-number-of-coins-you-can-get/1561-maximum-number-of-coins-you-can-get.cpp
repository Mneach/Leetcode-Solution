class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        
        int answer = 0;
        int end = piles.size() - 1;
        for(int i = 0; i < piles.size() / 3; i++){
            answer += piles[end - 1];
            end -= 2;
        }
        
        return answer;
    }
};