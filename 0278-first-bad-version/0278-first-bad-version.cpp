// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        
        for(int i = 1; i <= n; i++){
            if(isBadVersion(i) == true){
                return i;
            }
        }
        
        int left = 1;
        int right = n;
        
        int answer = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(isBadVersion(mid) == true){
                answer = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return answer;
    }
};