class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> answer;
        k--;
        
        if(k == 0) return 1;
        
        answer.push_back(n);
        for(int i = 2; i * i <= n; i++){
            
            if(i * i == n){
                k--;
            }else if(n % i == 0){
                answer.push_back(n / i);
                k--;
            }
            
            if(k == 0){
                return i;
            }
        }
        
        for(int i = answer.size() - 1; i >= 0; i--){
            k--;
            if(k == 0){
                return answer[i];
            }
        }
        
        return -1;
    }
};