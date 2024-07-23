class Solution {
public:

    // take
    // 0 -> plus
    // 1 -> minus

    int recursive(vector<int> &nums, vector<vector<int>> &arr, int currentIndex, int take){
        if(currentIndex >= nums.size()){
            return 0;
        }

        if(arr[currentIndex][0] != INT_MIN && arr[currentIndex][1] != INT_MIN){
            if(take == 0){
                return arr[currentIndex][0];
            }else{
                return arr[currentIndex][1];
            }
        }

        int resMinus = 1;
        int resPlus = 1;
        for(int i = currentIndex + 1; i < nums.size(); i++){
            if(nums[currentIndex] - nums[i] > 0){
                // take next minus
                resPlus = max(resPlus, 1 + recursive(nums, arr, i, 1));
            }else if(nums[currentIndex] - nums[i] < 0){
                // take next plus
                resMinus = max(resMinus, 1 + recursive(nums, arr , i, 0));
            }
        }

        arr[currentIndex][0] = max(arr[currentIndex][0], resPlus);
        arr[currentIndex][1] = max(arr[currentIndex][1], resMinus);
        
        return max(arr[currentIndex][0], arr[currentIndex][1]);
    }

    int wiggleMaxLength(vector<int>& nums) {

        vector<vector<int>> arr(nums.size(), vector<int>(2, INT_MIN));

        arr[nums.size() - 1][0] = 1;
        arr[nums.size() - 1][1] = 1;
        
        int answer = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            answer = max(answer, recursive(nums, arr , i, -1));
        }

        // for(auto data : arr){
        //     cout << data[0] << " " << data[1] << endl;
        // }

        return answer;
    }
};