class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> arr;
        
        for(int i = 0; i < stones.size(); i++){
            arr.push(stones[i]);
        }
        
        
        while(arr.size() > 1){
            int first = arr.top();
            arr.pop();
            int second = arr.top();
            arr.pop();
            
            int result = abs(first - second);
            
            if(result > 0){
                arr.push(result);
            }
        }
        
        return arr.size() == 0 ? 0 : arr.top();
    }
};