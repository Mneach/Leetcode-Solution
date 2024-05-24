class Solution {
public:
    
    int calculateScore(string s, vector<int> &score){
        int res = 0;
        for(auto data : s){
            res += score[data - 'a'];
        }
        
        return res;
    }
    
    bool validWords(string s, unordered_map<char, int> ump){
        
        for(auto data : s){
            if(ump[data] <= 0){
                return false;
            }
            
            ump[data]--;
        }
        
        return true;
    }
    
    void removeSubstring(string &s, string &sub) {
        auto pos = s.find(sub);
        if (pos != string::npos) {
            s.erase(pos, sub.length());
        }
    }
    
    void check(unordered_map<char, int> ump){
        for(auto data : ump){
            cout << data.first << " " << data.second << endl;
        }
        
        cout << endl;
    }
    
    void dfs(vector<string> &words, vector<char>& letters, vector<int> &score, int currentIndex, unordered_map<char, int> ump, int &answer, string s){
        
        if(currentIndex >= words.size()){
            answer = max(answer, calculateScore(s, score));
            return;
        }

        for(int i = currentIndex; i < words.size(); i++){
            if(validWords(words[i], ump)){
                s += words[i];
                for(auto data : words[i]){
                    ump[data]--;
                }
                
                answer = max(answer, calculateScore(s, score));
                dfs(words, letters, score, i + 1, ump, answer, s);
                
                for(auto data : words[i]){
                    ump[data]++;
                }
                
                removeSubstring(s, words[i]);
            }
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        
        unordered_map<char, int> ump;
        int answer = 0;
        
        for(auto data : letters){
            ump[data]++;
        }
        
        dfs(words, letters, score, 0, ump, answer, "");
        
        return answer;
    }
};