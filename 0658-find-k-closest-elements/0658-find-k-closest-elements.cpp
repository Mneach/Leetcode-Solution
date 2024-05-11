class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        if(arr.size() == k){
            return arr;
        }
        
        vector<int> answer;
        
        int left = 0;
        int right = arr.size() - 1;
        int mid = 0;
        
        // find closed elements
        while(left < right){
            mid = left + (right - left) / 2;
            
            if(arr[mid] >= x){
                right = mid;
            }else if(arr[mid] < x){
                left = mid + 1;
            }
        }
        
        right = left;
        left = right - 1;
        
        // using two pointer to get the range of answers
        while(right - left - 1 < k){
            // cout << left << " " << right <<  endl;
            if(left >= 0 && right < arr.size()){
                
                if(abs(arr[left] - x) <= abs(arr[right] - x)){
                    left--;
                }else{
                    right++;
                }
            }else if(left < 0 && right < arr.size()){
                right++;
            }else if(left > 0 && right >= arr.size()){
                left--;
            }
        }
        
        cout << left << " " << right << endl;
        
        // copy the answers
        for(int i = left + 1; i < right; i++){
            answer.push_back(arr[i]);
        }
        
        return answer;
    }
};