class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> answer;
        
        vector<int> bucket(nums.size() + 1, 0);
        
        for(int i = 0; i < nums.size(); i++){
            bucket[nums[i]]++;
        }
        
        for(int i = 0; i < bucket.size(); i++){
            cout << bucket[i] << " ";
        }
        
        while(true){
            vector<int> temp;
            bool checkEmpty = true;
            for(int i = 0; i < bucket.size(); i++){
                if(bucket[i] != 0) {
                    checkEmpty = false;
                    temp.push_back(i);
                    bucket[i]--;
                }
            }
            
            if(checkEmpty) break;
            answer.push_back(temp);
        }
        
        return answer;
    }
};