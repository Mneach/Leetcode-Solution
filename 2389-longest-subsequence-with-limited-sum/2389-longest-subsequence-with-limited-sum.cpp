class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> prefixSum(nums.size());
        vector<int> answer;
        
        
        prefixSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
        
        //for(int i = 0;i  < prefixSum.size(); i++){
            //cout << prefixSum[i] << endl;
        //}
        
        for(int i = 0; i < queries.size(); i++){
            int left = 0;
            int right = prefixSum.size() - 1;
            
            while(left <= right){
                int mid = (left + right) / 2;
                
                if(prefixSum[mid] > queries[i]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            
            answer.push_back(left);
        }
        
        return answer;
    }
};