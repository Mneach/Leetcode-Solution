class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
     
        map<char, int> hashmapWord1;
        map<char, int> hashmapWord2;
        
        for(int i = 0; i < word1.length(); i++){
            hashmapWord1[word1[i]]++;
            hashmapWord2[word2[i]]++;
        }
        
        for(auto x : hashmapWord1){
            if(hashmapWord2.find(x.first) != hashmapWord2.end()){
                if(x.second == hashmapWord2[x.first]) continue;
                else {
                    bool check = false;
                    int find = hashmapWord2[x.first];
                    for(auto y : hashmapWord1){
                        if(y.first > x.first){
                            if(find == y.second) {
                                int temp = x.second;
                                hashmapWord1[x.first] = y.second;
                                hashmapWord1[y.first] = temp;
                                cout << x.first << " " << x.second << endl;
                                cout << y.first << " " << y.second << endl;
                                check = true;
                                break;
                            }
                        }
                    }
                    
                    if(check == false) return false;
                }
            }else{
                return false;
            }
        }
        
        return true;
    }
};