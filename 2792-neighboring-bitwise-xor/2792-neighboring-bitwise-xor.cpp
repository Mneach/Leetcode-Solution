class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        if(derived.size() == 1 && derived[0] == 0) return true;
        else if(derived.size() == 1 && derived[0] == 1) return false;
        
        
        vector<int> original;
        for(int i = 0; i < derived.size() - 1; i++){
            if(i == 0 && derived[i] == 0){
                original.push_back(0);
                original.push_back(0);
            }else if(i == 0 && derived[i] == 1){
                original.push_back(0);
                original.push_back(1);
            }else if(i != 0){
                if(derived[i] == 0 && original[i] == 0){
                    original.push_back(0);
                }else if(derived[i] == 0 && original[i] == 1){
                    original.push_back(1);
                }else if(derived[i] == 1 && original[i] == 1){
                    original.push_back(0);
                }else if(derived[i] == 1 && original[i] == 0){
                    original.push_back(1);
                }
            }
        }
        
        for(int i = 0; i < derived.size(); i++){
            if(i == derived.size() - 1){
                if(original[i] ^ original[0] != derived[i]) return false;
            }else{
                if(original[i] ^ original[i + 1] != derived[i]) return false;
            }
        }
        
        return true;
    }
};