class Solution {
public:
    
    void bsta(vector<int> &answer, vector<int> mountain, int left, int right){
        
        if(left <= right){
            int mid = (left + right) / 2;
            
            if(mid == 0){
                if(mountain[mid + 1] > mountain[mid] && mountain[mid + 1] > mountain[mid + 2] && mountain.size() > 3){
                    answer.push_back(mid + 1);
                }
                
                return;
            }else if(mid == mountain.size() - 1){
                return;
            }else if(mountain[mid] > mountain[mid + 1] && mountain[mid] > mountain[mid - 1]){
                answer.push_back(mid);
            }
            
            bsta(answer, mountain, left , mid - 1);
            bsta(answer, mountain, mid + 1, right);
        }
    }
    
    vector<int> findPeaks(vector<int>& mountain) {
        
        vector<int> answer;
        bsta(answer, mountain, 1, mountain.size() - 2);
        
        return answer;
    }
};