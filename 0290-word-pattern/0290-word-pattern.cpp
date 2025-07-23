class Solution {
public:
    bool wordPattern(const string& pattern, const string& str) {
    unordered_map<char, int> charIndex;
    unordered_map<string, int> wordIndex;
    istringstream stream(str);
    
    string word;
    int index = 0;

    for (; stream >> word; ++index) {
        if (index >= pattern.size()) return false;

        char c = pattern[index];
        if (charIndex[c] != wordIndex[word])
            return false;

        charIndex[c] = wordIndex[word] = index + 1;
    }

    return index == pattern.size();
}
};