class Solution {
public: 
    
    int hIndex(vector<int>& arr) {
       
        int left = 0;
        int right = arr.size() - 1;
        
        int hIndex = 0;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            int totalPaper = arr.size() - mid;
            // cout << mid << " " << totalPaper << " " << arr[mid] << endl;
            if(arr[mid] >= totalPaper){
                hIndex = max(hIndex, totalPaper);
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return hIndex;
    }
};