class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<int> arr(26, 0);
        
        for(int i = 0; i < sentence.size(); i++){
            arr[sentence[i] - 'a' ]++;
        }
        
        bool answer = true;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 0) {
                answer = false;
                break;
            }
        }
        
        return answer;
    }
};