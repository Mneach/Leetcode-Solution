class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int totalCircular = 0;
        int totalSquare = 0;
        
        for(auto data : students){
            if(data == 0){
                totalCircular++;
            }else{
                totalSquare++;
            }
        }
        
        for(auto sandwich : sandwiches){
            
            if(sandwich == 1 && totalSquare == 0) return totalCircular;
            
            if(sandwich == 0 && totalCircular == 0) return totalSquare;
            
            if(sandwich == 0){
                totalCircular--;
            }else{
                totalSquare--;
            }
        }
        
        return 0;
    }
};