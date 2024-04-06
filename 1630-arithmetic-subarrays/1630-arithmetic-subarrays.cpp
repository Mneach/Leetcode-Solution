class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> answer;
        
        for(int i = 0; i < l.size(); i++){
            
            int minimum = INT_MAX;
            int maximum = INT_MIN;
            
            unordered_map<int, int> ump;
            for(int j = l[i]; j <= r[i]; j++){
                minimum = min(nums[j], minimum);
                maximum = max(nums[j], maximum);
                ump[nums[j]]++;
            }
            
           
            
            int n = r[i] - l[i];
            
            if ((maximum - minimum) % (n) != 0) {
                answer.push_back(false);
                continue;
            }
            
            int diff = (maximum - minimum) / (n);
            
             // cout << minimum << " " << maximum << " " << n << " " << diff << endl;
            
            bool temp = true;
            for(int j = 0; j <= n; j++){
                if(ump.count(minimum + (diff * j)) != 1){
                    temp = false;
                }
            }
            
            answer.push_back(temp);
        }
        
        return answer;
    }
};