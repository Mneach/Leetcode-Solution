class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> ump;
        unordered_map<int,int> answer;

        for(auto data : nums){
            ump[data]++;
        }

        int limit = k == 0 ? 1 : 0;

        for(auto data : nums){
            int find1 = data - k;
            int find2 = data + k;
            int minValue1 = min(data, find1);
            int minValue2 = min(data, find2);

            if(ump[find1] > limit && ump[find2] > limit && answer[minValue1] == 0 && answer[minValue2] == 0){
                answer[minValue1] = max(data, find1);
                answer[minValue2] = max(data, find2);
            }else if(ump[find1] > limit && answer[minValue1] == 0){
                answer[minValue1] = max(data, find1);
            }else if(ump[find2] > limit && answer[minValue2] == 0){
                answer[minValue2] = max(data, find2);
            }
        }

        return answer.size();
    }
};