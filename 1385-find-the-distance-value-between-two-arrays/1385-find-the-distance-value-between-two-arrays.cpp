class Solution {
public:
    
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        
        int answer = 0;
        sort(arr2.begin(), arr2.end());
        for(int i = 0; i < arr1.size(); i++){
            int left = 0;
            int right = arr2.size() - 1;
            
            bool valid = true;
            
            int A = arr1[i];
            while(left <= right){
                int mid = (left + right) / 2;
                int B = arr2[mid];
                
                if(A - d <= B && A + d >= B){
                    valid = false;
                    break;
                }else if(A - d > B){
                    left = mid + 1;
                }else if(A + d < B){
                    right = mid - 1;
                }
                
            }
                
            //cout << endl;
            if(valid){
                answer++;
            }
        }
        
        return answer;
    }
};