class Solution {
public:
    string clearStars(string s) {
        map<char,vector<int>> mp;
        unordered_map<int,int> excludeIndex;
        
        for(int i = 0; i < s.length(); i++){
            char character = s[i];
            
            if(character == '*'){
                // find left
                auto pointToFirstElement = mp.begin();
                int vectorSize = pointToFirstElement->second.size();
                
                excludeIndex[ pointToFirstElement->second[vectorSize - 1] ]++;
                
                // check if the map value == 0, remove the element
                if(vectorSize == 1){
                    mp.erase(pointToFirstElement -> first);
                }else{
                    // remove index on vector
                    pointToFirstElement->second.pop_back();
                }
            }else{
                // store to the map
                mp[character].push_back(i);
            }
        }
        
        string answer = "";
        
        for(int i = 0; i < s.length(); i++){
            if(excludeIndex[i] > 0 || s[i] == '*') continue;
            
            answer += s[i];
        }
        
        return answer;
    }
};