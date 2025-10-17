class Solution {
public:
    int findMin(vector<int>& nums) {

       int size = nums.size();
       int left = 0;
       int right = size - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            cout << left << " " << mid << " " << right << endl;
            if(nums[mid] > nums[size - 1]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return nums[left];
    }
};