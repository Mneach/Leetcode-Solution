class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int answer = 0;

        vector<int> row(rooks.size(), 0);
        vector<int> col(rooks.size(), 0);

        for(int i = 0; i < rooks.size(); i++){
            row[rooks[i][0]]++;
            col[rooks[i][1]]++;
        }

        int rowMove = 0;
        int colMove = 0;

        for(int i = 0; i < rooks.size(); i++){
            rowMove += row[i] - 1;
            colMove += col[i] - 1;

            cout << rowMove << " " << colMove << endl;

            answer += abs(rowMove) + abs(colMove);
        }

        return answer;
    }
};