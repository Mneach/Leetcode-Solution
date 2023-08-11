class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        arr.insert(arr.begin(), 0);
        
        for(int i = 1; i < arr.size(); i++){
           arr[i] = arr[i] ^ arr[i - 1]; 
        }
        
        int answer = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                if(arr[i] == arr[j]){
                    answer += j - i - 1;
                }
            }
        }
        
        return answer;
    }
};