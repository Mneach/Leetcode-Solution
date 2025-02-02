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

            answer = max({answer, distance, min(totalChar, distance + (k * 2))});
        }

        return answer;
    }
};

