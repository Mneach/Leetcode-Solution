class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int answer = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int playerIndex = 0;
        int trainerIndex = 0;

        while (playerIndex < players.size() && trainerIndex < trainers.size()) {
            // find suitable trainer
            int player = players[playerIndex];

            while (trainerIndex < trainers.size()) {
                if (trainers[trainerIndex] >= player) {
                    answer++;
                    trainerIndex++;
                    break;
                }
                trainerIndex++;
            }
            playerIndex++;
        }
        
        return answer;
    }
};