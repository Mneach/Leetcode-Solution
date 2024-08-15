class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> ump;

        for(auto data : bills){
            if(data == 5){
                ump[5]++;
            }else if(data == 10){
                if(ump[5] <= 0){
                    return false;
                }else{
                    ump[5]--;
                }

                ump[10]++;
            }else if(data == 20){
                if(ump[10] > 0 && ump[5] > 0){
                    ump[10]--;
                    ump[5]--;
                }else if(ump[5] >= 3){
                    ump[5] -= 3;
                }else{
                    return false;
                }

                ump[20]++;
            }
        }

        return true;
    }
};