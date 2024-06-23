class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pair<int,int>> pqMax;
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pqMin;

        int answer = 0;
        int left = 0;
        int size = nums.size();

        for(int i = 0; i < nums.size(); i++){
            pqMax.push({nums[i], i});
            pqMin.push({nums[i], i});

            if(pqMax.top().first - pqMin.top().first > limit){
                if(pqMax.top().second < pqMin.top().second){
                    left = pqMax.top().second + 1;
                    
                    while(pqMax.size() > 0 && pqMax.top().second < left){
                        pqMax.pop();
                    }
                }else{
                    left = pqMin.top().second + 1;
                    
                    while(pqMin.size() > 0 && pqMin.top().second < left){
                        pqMin.pop();
                    }
                }
            }

            answer = max(answer, (i - left) + 1);
        }

        answer = max(answer, size - left);

        return answer;
    }
};