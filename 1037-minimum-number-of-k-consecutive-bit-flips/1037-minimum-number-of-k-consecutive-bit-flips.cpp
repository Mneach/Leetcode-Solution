class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int answer = 0;        
        int right = INT_MAX;
        priority_queue<int, vector<int>, greater<int>> pq;

        int flip = 0;

        for(int i = 0; i < nums.size(); i++){
            
            if(pq.size() > 0 && i == pq.top()){
                pq.pop();
                flip--;
            }

            if((nums[i] + flip) % 2 == 0){

                if(i + k > nums.size()) return -1;

                pq.push(i + k);
                answer++;
                flip++;
            }
        }

        return answer;
    }
};