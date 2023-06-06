class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        vector<int> travelingHouseDistance(travel.size() + 1, 0);
        
        for(int i = 1; i <= travel.size(); i++){
            travelingHouseDistance[i] = travel[i - 1] + travelingHouseDistance[i - 1];
        }
        
        
        int totalMinuteMetal = 0;
        int totalMinutePaper = 0;
        int totalMinuteGlass = 0;
        int totalMinuteGarbage = 0;
        
        for(int i = 0; i < garbage.size(); i++){
            if(garbage[i].find("M") != string::npos) totalMinuteMetal = travelingHouseDistance[i];
            if(garbage[i].find("P") != string::npos) totalMinutePaper = travelingHouseDistance[i];
            if(garbage[i].find("G") != string::npos) totalMinuteGlass = travelingHouseDistance[i];
            
            totalMinuteGarbage += garbage[i].size();
            
        }
        
        return totalMinuteMetal + totalMinutePaper + totalMinuteGlass + totalMinuteGarbage;
    }
};