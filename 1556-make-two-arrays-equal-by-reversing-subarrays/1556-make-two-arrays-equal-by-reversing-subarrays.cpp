class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> ump;

        for(auto data : target) ump[data]++;

        for(auto data : arr) {
            if(ump[data] > 0){
                ump[data]--;
            }else{
                return false;
            }
        }

        

        return true;
    }
};