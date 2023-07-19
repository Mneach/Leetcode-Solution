class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        size_t position = s.find(part);
        
        while(position != string::npos){
            s.erase(position, part.size());
            position = s.find(part);
        }
        
        return s;
    }
};