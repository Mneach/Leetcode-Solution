class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> bucket(1e6 + 2, 0);

        for(auto data : nums){
            bucket[data]++;
        }

        int answer = 0;

        int maximum = 0;
        for(int i = 0; i <= 1e6 + 1; i++){
            if(bucket[i] > 1){
                while(bucket[i] > 1){
                    bucket[i]--;
                    pq.push(i);
                }
            }else if(bucket[i] == 0){
                if(pq.size() > 0){
                    answer += i - pq.top();
                    pq.pop();
                }
            }
        }

        return answer;
    }
};