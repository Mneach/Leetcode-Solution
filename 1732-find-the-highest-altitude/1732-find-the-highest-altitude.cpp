class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int maximum = -100;
        int currentGain = 0;
        for(int i = 0; i < gain.size(); i++){
            currentGain += gain[i];
            maximum = max(currentGain, maximum);
        }
        
        if(maximum < 0) return 0;
        else return maximum;
    }
};