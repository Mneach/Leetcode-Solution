class Solution {
public:
    
    long long int maxLL(long long a, long long b){
        if(a > b) return a;
        else return b;
    }
    
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<long long> pq;
        long long answer = 0;
        long long take = 0;
        
        for(auto data : happiness){
            pq.push(data);
        }
        
        while(k--){
            answer += maxLL(0, pq.top() - take);
            take++;
            pq.pop();
        }
        
        return answer;
    }
};