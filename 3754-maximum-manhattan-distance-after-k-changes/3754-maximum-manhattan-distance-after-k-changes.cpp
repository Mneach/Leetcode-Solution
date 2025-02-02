/*
Intuition : 
1. We need to move as far as we can
2. for horizontal direction, we just need to move either to left or right
3. for vertial direction, we just need to move either to top or right
4. the answer should be between these values
   - abs(horizontal direction) + abs(vertical direction)
   - abs(horizontal direction) + abs(vertical direction) + use k value to convert the direction 
*/
class Solution {
public:
    int maxDistance(string s, int k) {
        
        int answer = 0;
        int positionX = 0;
        int positionY = 0;
        int totalChar = 0;

        for (auto c : s) {
            totalChar++;            
            if (c == 'N') positionY++;
            else if (c == 'S') positionY--;
            else if (c == 'W') positionX++;
            else if (c == 'E') positionX--;

            int distance = abs(positionX) + abs(positionY);

            // reason why we use k * 2
            // because we want to convert all the negative direction to the current direction
            // the reason we put min(totalChar, distance + K (k * 2)) is because there is a case
            // when k * 2 is more than our total character
            answer = max({answer, distance, min(totalChar, distance + (k * 2))});
        }

        return answer;
    }
};

