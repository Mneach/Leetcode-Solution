class Solution {
public:
    
    void recursive(int n, int k, int currentPosition, vector<int> &arr){
        
        if(n == 1) return;
       
        int temp = 0;
        while(true){
            
            if(arr[currentPosition] == 1){
                temp++;
            }
            
            if(temp == k) break;
            
            currentPosition = (currentPosition + 1) % arr.size();
        }
        
        arr[currentPosition] = 0;
        
        recursive(n - 1, k , (currentPosition + 1) % arr.size(), arr);
    }
    
    int findTheWinner(int n, int k) {
        
        vector<int> arr(n, 1);
        
        recursive(n, k, 0, arr);
        
        int answer = 1;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == 1){
                answer = i;
                break;
            }
        }
        
        return answer + 1;
    }
};