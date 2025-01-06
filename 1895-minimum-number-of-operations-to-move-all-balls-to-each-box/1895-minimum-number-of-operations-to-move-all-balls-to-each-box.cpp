class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int lenght = boxes.size();
        vector<int> answer(lenght);
        
        int sum = boxes[0] - '0';
        
        int leftSum = 0;
        for(int i = 1; i < lenght; i++){
            answer[i] = sum + leftSum;
            leftSum = answer[i];
            sum += boxes[i] - '0';
        }
        
        for(int i = 0; i < lenght; i++){
            cout << answer[i] << endl;
        }
        
        leftSum = 0;
        sum = boxes[lenght - 1] - '0';
        
        for(int i = lenght - 2; i >= 0; i--){
            answer[i] += leftSum + sum;
            leftSum += sum;
            sum += boxes[i] - '0';
        }
        
        return answer;
    }
};