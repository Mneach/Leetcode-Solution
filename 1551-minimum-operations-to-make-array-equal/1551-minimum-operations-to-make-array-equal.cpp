class Solution {
public:
    int minOperations(int n) {
        int mid = n;
        
        int start = 1;
        int answer = 0;
        
        while(start <= n){ 
            answer += mid - start;
            start += 2;
        }
        
        return answer;
    }
};