class Solution {
public:
    int pivotInteger(int n) {
        
        vector<int> prefixSum;
        
        prefixSum.push_back(0);
        
        for(int i = 1; i <= n; i++){
            prefixSum.push_back(i + prefixSum[i - 1]);
        }
        
        for(auto data : prefixSum){
            cout << data << " " ;
        }
        
        int answer = -1;
        int right = prefixSum.size() - 1;
        
        while(right > 0){
            int leftSum = prefixSum[right];
            int rightSum = prefixSum[prefixSum.size() - 1] - prefixSum[right - 1];
            
            if(leftSum == rightSum){
                answer = right;
                break;
            }
            
            right--;
        }
        
        return answer;
    }
};