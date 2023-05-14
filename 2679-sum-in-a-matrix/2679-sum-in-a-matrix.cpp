class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int row = nums.size();
        int column = nums[0].size();
        
        for(int i = 0; i < row; i++){
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        }
        
        int answer = 0;
        for(int i = 0; i < column; i++){
            
            int maxNumber = 0;
            for(int j = 0; j < row; j++){
                maxNumber = max(maxNumber, nums[j][i]);
            }
            cout << maxNumber << endl;
            answer += maxNumber;
        }
        
        return answer;
    }
};