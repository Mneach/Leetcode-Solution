
struct Node{
    int positionX, positionY;
    
    Node(int x, int y) : positionX(x), positionY(y){}
};

class Solution {
public:
    
    bool checkValidTile(vector<Node> queenPosition, Node currentPosition, int n){
        
        bool check = true;
        
        // check column
        for(auto data : queenPosition){
            if(data.positionY == currentPosition.positionY){
                check = false;
            }
        }
        
        // check diagnoal
        for(auto data : queenPosition){
            int queenPositionX = data.positionX;
            int queenPositionY = data.positionY;
            
            // left bottom diagnoal of the current queen position
            while(queenPositionX < n && queenPositionY >= 0){
                if(currentPosition.positionX == queenPositionX && currentPosition.positionY == queenPositionY){
                    check = false;
                }
                
                queenPositionX++;
                queenPositionY--;
            }
            // right bottom diagnoal of the  current queen position
            queenPositionX = data.positionX;
            queenPositionY = data.positionY;
            while(queenPositionX < n && queenPositionY < n){
                if(currentPosition.positionX == queenPositionX && currentPosition.positionY == queenPositionY){
                    check = false;
                }
                
                queenPositionX++;
                queenPositionY++;
            }
        }
        
        return check;
    }
    
     void pushAnswer(vector<vector<string>> &answers, vector<Node> queenPosition, int n){
        
        vector<string> tempAnswers;
        for(int i = 0; i < n; i++){
            string temp = "";
            for(int j = 0; j < n; j++){
                temp += '.';
            }
            
            tempAnswers.push_back(temp);
        }
        
        answers.push_back(tempAnswers);
        
        for(auto data : queenPosition){
            //cout << data.positionX << " " << data.positionY << endl;
            answers[answers.size() - 1][data.positionX][data.positionY] = 'Q';
        }
    }
    
    void recursive(int currentRow, int n, vector<Node> queenPosition, vector<vector<string>> &answers){
        
        for(int column = 0; column < n; column++){
            Node currentPosition(currentRow, column);
           
            if(checkValidTile(queenPosition, currentPosition, n) == true){
                queenPosition.push_back(currentPosition);
                //cout << currentPosition.positionX << " " << currentPosition.positionY << endl;
                
                if(currentRow == n - 1){
                    pushAnswer(answers, queenPosition, n);
                }
                
                recursive(currentRow + 1, n , queenPosition, answers);
                queenPosition.erase(queenPosition.begin() + queenPosition.size() - 1);
            }
        }
    }
    
   
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answers;
        vector<Node> queenPosition;
        
        recursive(0, n, queenPosition, answers);
        
        return answers;
    }
};





