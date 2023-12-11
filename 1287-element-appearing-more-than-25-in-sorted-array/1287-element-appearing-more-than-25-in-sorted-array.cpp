class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
       map<int,int> bucket; 
       int minimum = arr.size() / 4;
       
       for(int i = 0; i < arr.size(); i++){
           bucket[arr[i]]++;
       }
        
       int answer = 0;
       for(auto data : bucket){
           if(data.second > minimum){
               answer = data.first;
           }
       }
        
       return answer;
    }
};