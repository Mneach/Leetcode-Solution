class Solution {
public:
    string removeOccurrences(string s, string part) {
       
        while(true){
            if(s.find(part) == string::npos) break;
            else {
                int start = s.find(part);
                
                s.erase(start, part.size());
            }
        }
        
        return s;
    }
};