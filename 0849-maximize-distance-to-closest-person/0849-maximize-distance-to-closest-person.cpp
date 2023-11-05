class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int leftPointer = 0;
        int answer = 0;
        
        for(int i = 0; i < seats.size(); i++){
            if(seats[i] == 1){
                if(seats[leftPointer] == 0){
                   answer = max(answer, i - leftPointer); 
                }else{
                   answer = max(answer, (i - leftPointer) / 2);
                }
                leftPointer = i;
            }
        }
        
        int size = seats.size();
        answer = max(answer, size - leftPointer - 1);
        
        return answer;
    }
};