class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> answer;
        
        // sort the potion data
        sort(potions.begin(), potions.end());
    
        for(int i = 0; i < spells.size(); i++){
            
            long long int currentSpells = spells[i];
            
            // do a binary search
            // you need to find the minimum index posisiton that fullfill this condition
            // if spells[i] * potions[mid] >= success
            
            int left = 0;
            int right = potions.size() - 1;
            int localAnswerIndex = INT_MAX;
            
            while(left <= right){
                int mid = left + (right - left) / 2;
                long long int currentResult = (long long int) spells[i] * potions[mid];
                
                if(currentResult >= success){
                    localAnswerIndex = min(localAnswerIndex, mid);
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            
            if(localAnswerIndex == INT_MAX){
                answer.push_back(0);
            }else{
                answer.push_back(potions.size() - localAnswerIndex);
            }
            
            
        }
        
        return answer;
    }
};