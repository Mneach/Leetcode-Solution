class Solution {
public:

    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> ump;

        for(auto number : nums){
            ump[number]++;
        }

        int answer = -1;
        for(int i = 0; i < nums.size(); i++){
            if(ump[nums[i]] <= 0){
                continue;
            }else{
                long long current = nums[i];
                int temp = 0;
                while(ump[current] > 0){
                    temp++;
                    current = (current * current);
                    if(current > 1e5) break;
                }

                if(temp == 1) continue;

                answer = max(temp, answer);
            }
        }

        return answer;
    }
};