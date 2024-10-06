class Solution {
private:
    string extract(string s, int index){

        string result = "";
        for(int i = index; i < s.length(); i++){
            if(s[i] == ' ') break;
            result += s[i];
        }

        return result;
    }

public:
    bool areSentencesSimilar(string sentence1, string sentence2) {

        if(sentence1 == sentence2) return true;

        stringstream ss1(sentence1), ss2(sentence2);
        string word;
        vector<string> s1, s2;
        while (ss1 >> word) s1.push_back(word);
        while (ss2 >> word) s2.push_back(word);

        if(s1.size() > s2.size()){
            return areSentencesSimilar(sentence2, sentence1);
        }

        int start = 0;
        
        while(start < s1.size() && s1[start] == s2[start]){
            start++;
        }

        int end1 = s1.size() - 1;
        int end2 = s2.size() - 1;

        while(end1 >= 0 && s1[end1] == s2[end2]){
            end1--;
            end2--;
        }

        return end1 < start;
    }
};