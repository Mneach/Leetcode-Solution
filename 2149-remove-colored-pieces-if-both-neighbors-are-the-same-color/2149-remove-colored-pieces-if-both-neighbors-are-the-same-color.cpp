class Solution {
public:
    bool winnerOfGame(string colors) {
        int length = colors.length();
        int aliceIndex = 0;
        int bobIndex = 0;

        // 0 -> alice move
        // 1 -> bob move
        bool turn = 0;

        while(aliceIndex < length - 1 && bobIndex < length - 1) {
            int count = 1;
            if (turn == 0) {
                // alice move
                while (count < 3 && aliceIndex < length - 1) {
                    if (colors[aliceIndex] == 'A' && colors[aliceIndex] == colors[aliceIndex + 1]) {
                        count++;
                    } else {
                        count = 1;
                    }
                    aliceIndex++;
                }
                if (count == 3) {
                    aliceIndex--;
                }
                turn = 1;
            } else {
                // bob move
                while (count < 3 && bobIndex < length + 1) {
                    if (colors[bobIndex] == 'B' && colors[bobIndex] == colors[bobIndex + 1]) {
                        count++;
                    } else {
                        count = 1;
                    }
                    bobIndex++;
                }

                if (count == 3) {
                    bobIndex--;
                }
                
                turn = 0;
            }
        }

        return aliceIndex < bobIndex;
    }
};