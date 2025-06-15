class Solution {
public:
    string generateTag(string caption) {
        string tag = "#";
        bool newWord = true;  // Flag to track if we're at the start of a new word
        
        for (char c : caption) {
            if (c == ' ') {
                newWord = true;
                continue;
            }
            
            if (newWord) {
                tag += toupper(c);
                newWord = false;
            } else {
                tag += tolower(c);
            }
            
            // Early exit if we reach maximum length
            if (tag.size() >= 100) break;
        }
        
        // Ensure first character after '#' is lowercase
        if (tag.size() > 1) {
            tag[1] = tolower(tag[1]);
        }
        
        return tag.substr(0, 100);  // Ensure max length of 100 characters
    }
};