class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

       priority_queue<long long> pq; 
       long long answer = 0;

       for(auto data : nums){
            pq.push(data);
       }

       while(k > 0){
            long long temp = pq.top();
            cout << temp << endl;
            pq.pop();

            answer += temp;
            temp = ceil((double)temp / 3);
            pq.push(temp);
            k--;
       }

       return answer;
    }
};