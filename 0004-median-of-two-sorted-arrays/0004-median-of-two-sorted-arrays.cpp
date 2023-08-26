class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        int currentIndexN = 0;
        int currentIndexM = 0;
        
        vector<int> arr;
        
        while(currentIndexN < n && currentIndexM < m){
            if(nums1[currentIndexN] < nums2[currentIndexM]){
                arr.push_back(nums1[currentIndexN]);
                currentIndexN++;
            }else{
                arr.push_back(nums2[currentIndexM]);
                currentIndexM++;
            }
        }
        
        while(currentIndexN < n){
            arr.push_back(nums1[currentIndexN]);
            currentIndexN++;
        }
        
        while(currentIndexM < m){
            arr.push_back(nums2[currentIndexM]);
            currentIndexM++;
        }
        
        int mid = (n + m) / 2;
        double answer = arr[mid];
        
        if((n + m) % 2  == 0) answer = (answer + arr[mid - 1]) / 2;
        
        return answer;
    }
};