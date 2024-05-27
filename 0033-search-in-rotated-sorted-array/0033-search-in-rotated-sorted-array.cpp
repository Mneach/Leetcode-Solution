class Solution {
public:

    int binarySearch(vector<int>& nums, int target, int left, int right){
        cout << left << " " << right << endl;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        
        int size = nums.size();
        int left = 0;
        int right = size - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[size - 1]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        cout << left << " " << right << endl;

        int answer = binarySearch(nums, target, 0, left - 1);

        if(answer == -1){
            answer = binarySearch(nums, target, left, size - 1);
        }

        return answer;
    }
};