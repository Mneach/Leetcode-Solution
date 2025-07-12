class Solution {
private:
    vector<int> answer = {INT_MAX, INT_MIN};
public:

    void recursive(int mask, int left, int right, int firstPlayer, int secondPlayer, int round) {
        if (left >= right) {
            // reset and move to the next round
            recursive(mask, 0, 27, firstPlayer, secondPlayer, round + 1); 
        } else if ((mask & (1 << left)) == 0) {
            // current player is already defeted, so skip the current player
            recursive(mask, left + 1, right, firstPlayer, secondPlayer, round);
        } else if ((mask & (1 << right)) == 0) {
            // current play is already defeted, so skip the current player
            recursive(mask, left, right - 1, firstPlayer, secondPlayer, round);
        } else if (left == firstPlayer && right == secondPlayer) {
            // base case
            answer[0] = min(answer[0], round);
            answer[1] = max(answer[1], round);
            return;
        } else {
            if (left != firstPlayer && left != secondPlayer) {
                // choose right as a winner first
                // mark left as defeted player
                int newMask = mask ^ (1 << left);
                recursive(newMask, left + 1, right - 1, firstPlayer, secondPlayer, round);
            } 
            
            if (right != firstPlayer && right != secondPlayer) {
                // choose left as a winner 
                // mark right as defeted player
                int newMask = mask ^ (1 << right); 
                recursive(newMask, left + 1, right - 1, firstPlayer, secondPlayer, round);
            }
        } 
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int mask = (1 << n) - 1;
        recursive(mask, 0, 27, firstPlayer - 1, secondPlayer - 1, 1);
        return answer;
    }
};