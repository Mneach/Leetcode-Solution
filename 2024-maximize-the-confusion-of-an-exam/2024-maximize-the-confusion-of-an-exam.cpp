class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int> arr;
        
        int answer = 0;
        int left = 0;
        for(int i = 0; i < answerKey.length(); i++){
            
            arr[answerKey[i]]++;
            int minimum = min(arr['T'], arr['F']);
            
            if(minimum > k){
                arr[answerKey[i - answer]]--;
                left++;
            }else{
                answer++;
            }
        }
        
        return answer;
    }
};