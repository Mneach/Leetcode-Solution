class Solution {
private:
    vector<int> answer = {INT_MAX, INT_MIN};
    bool dp[28][28][28] = {false};
public:

    void recursive(int mask, int left, int right, int firstPlayer, int secondPlayer, int round, int leftPart, int middlePart, int rightPart) {
        if (left >= right) {
            // reset and move to the next round
            recursive(mask, 0, 27, firstPlayer, secondPlayer, round + 1, leftPart, middlePart, rightPart); 
        } else if ((mask & (1 << left)) == 0) {
            // current player is already defeted, so skip the current player
            recursive(mask, left + 1, right, firstPlayer, secondPlayer, round, leftPart, middlePart, rightPart);
        } else if ((mask & (1 << right)) == 0) {
            // current play is already defeted, so skip the current player
            recursive(mask, left, right - 1, firstPlayer, secondPlayer, round, leftPart, middlePart, rightPart);
        } else if (left == firstPlayer && right == secondPlayer) {
            // base case
            answer[0] = min(answer[0], round);
            answer[1] = max(answer[1], round);
            return;
        } else {
            // dp[leftPart][middlePart][rightPart] = true;
            if (left != firstPlayer && left != secondPlayer) {
                // choose right as a winner first
                // mark left as defeted player
                int newMask = mask ^ (1 << left);
                leftPart = leftPart - (left < firstPlayer);
                middlePart = middlePart - (left > firstPlayer && left < secondPlayer);
                rightPart = rightPart - (left > secondPlayer);
                recursive(newMask, left + 1, right - 1, firstPlayer, secondPlayer, round, leftPart, middlePart, rightPart);
            } 
            
            if (right != firstPlayer && right != secondPlayer) {
                // choose left as a winner 
                // mark right as defeted player
                int newMask = mask ^ (1 << right); 
                leftPart = leftPart - (right < firstPlayer);
                middlePart = middlePart - (right > firstPlayer && right < secondPlayer);
                rightPart = rightPart - (right > secondPlayer);
                recursive(newMask, left + 1, right - 1, firstPlayer, secondPlayer, round, leftPart, middlePart, rightPart);
            }
        } 
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int mask = (1 << n) - 1;
        int leftPart = firstPlayer - 1;
        int middlePart = secondPlayer - firstPlayer - 1;
        int rightPart = n - secondPlayer;
        recursive(mask, 0, 27, firstPlayer - 1, secondPlayer - 1, 1, leftPart, middlePart, rightPart);
        return answer;
    }
};