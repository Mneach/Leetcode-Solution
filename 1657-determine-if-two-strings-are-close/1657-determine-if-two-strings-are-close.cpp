class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.length() != word2.length()) return false;
        
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);
        
        set<char> string1, string2;
        
        for(int i = 0; i < word1.size(); i++) {
            arr1[word1[i] - 'a']++;
            string1.insert(word1[i]);
        }
        for(int i = 0; i < word2.size(); i++) {
            arr2[word2[i] - 'a']++;
            string2.insert(word2[i]);
        }
        
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        
        return arr1 == arr2 && string1 == string2;        
    }
};