class Solution {
public:
    int findMin(vector<int>& nums) {

       int size = nums.size();
       int left = 0;
       int right = size - 1;
       int find = right;

       while(left < find && nums[left] == nums[find]){
            find--;
       }

        if(left > find){
            return nums[0];
        }

        cout << find << endl;

        right = find;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[find]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return nums[left];
    }
};