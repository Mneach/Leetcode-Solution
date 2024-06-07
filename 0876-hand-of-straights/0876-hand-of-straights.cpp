class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> myMap;
        for(auto data : hand) myMap[data]++;

        if(hand.size() % groupSize != 0) return false;

        int total = 0;
        int prev = -1;

        map<int, int>::iterator it = myMap.begin();

        while(it != myMap.end()){
            int current = it->first;
            
            if(total == 0){
                prev = current;
                total++;
            }else if(total == groupSize){
                if(it->second == 0){
                    myMap.erase(it -> first);
                }

                it = myMap.begin();

                total = 0;
                prev = -1;
                continue;
            }else{
                if(prev + 1 != current){
                    return false;
                }
                prev = current;
                total++;
            }
            
            
           
            myMap[it->first]--;
            
            if(it->second == 0){
                myMap.erase(it -> first);
            }

            it++;

            if(it == myMap.end() && myMap.begin()->second > 0){
                it = myMap.begin();
            }
        }

        for(auto data : myMap){
            cout << data.first << " " << data.second << endl;
        }

        if(total != groupSize) return false;

        return true;
    }
};