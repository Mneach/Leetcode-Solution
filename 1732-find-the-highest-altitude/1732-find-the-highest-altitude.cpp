class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int result = 0;
        int currentGain = 0;
        
        for(int i = 0; i < gain.size(); i++){
            currentGain += gain[i];
            result = max(currentGain, result);
        }
        
        return result;
    }
};