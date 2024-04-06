class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> answer;
        
        for(int i = 0; i < l.size(); i++){
            
            vector<int> bucket;
            for(int j = l[i]; j <= r[i]; j++){
                bucket.push_back(nums[j]);
            }
            
            sort(bucket.begin(), bucket.end());
            
            bool temp = true;
            
            int diff = -1;
            for(int i = 0; i < bucket.size() - 1; i++){
                if(i == 0){
                    diff = abs(bucket[i] - bucket[i + 1]);
                }else{
                    if(abs(bucket[i] - bucket[i + 1]) != diff){
                        temp = false;
                        break;
                    }
                }
            }
            
            answer.push_back(temp);
        }
        
        return answer;
    }
};