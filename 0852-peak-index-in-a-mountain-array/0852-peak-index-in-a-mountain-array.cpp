class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int answer = 0;
        
        for(int i = 0; i < arr.size(); i++){
            
            int left = 0;
            int right = arr.size() - 1;
            
            while(left <= right){
                int mid = (left + right) / 2;
                
                if(mid == 0){
                    answer = mid + 1;
                    break;
                }else if(mid == arr.size() - 1){
                    answer = arr.size() - 2;
                    break;
                }
                
                if(arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1]){
                    answer = mid;
                    break;
                }else if(arr[mid] < arr[mid - 1]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
        
        return answer;
    }
};