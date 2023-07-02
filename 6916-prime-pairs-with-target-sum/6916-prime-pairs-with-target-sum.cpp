class Solution {
public:
    
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> answer;
        
        // pre compute prime number
        vector<bool> prime(10000000, true);
        
        for(int i = 2; i <= sqrt(1000000); i++){
            if(prime[i] == true){
                for(int j = i * i; j <= 1000000; j += i) prime[j] = false;
            }
        }
        
        for(int i = 2; i <= n / 2; i++){
            if(prime[i] == false || prime[n - i] == false) continue;
            else if(i + (n - i) == n && prime[i] == true && prime[n - i] == true) answer.push_back({i , n - i});
        }
        
        return answer;
    }
};