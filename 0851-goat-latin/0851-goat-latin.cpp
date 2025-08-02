class Solution {
    const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                    'A', 'E', 'I', 'O', 'U'};

public:
    string toGoatLatin(string sentence) {
        istringstream iss(sentence);
        string word, result;
        string suffix = "a";  // Start with one 'a' for the first word
        
        while (iss >> word) {
            // Process current word
            if (!vowels.count(word[0])) {
                // If consonant, move first letter to end
                word = word.substr(1) + word[0];
            }
            
            // Add "ma" and the increasing 'a's
            word += "ma" + suffix;
            
            // Append to result with space
            result += word + " ";
            
            // Grow the suffix for next word
            suffix += "a";
        }
        
        // Remove trailing space before returning
        if (!result.empty()) {
            result.pop_back();
        }
        
        return result;
    }
};