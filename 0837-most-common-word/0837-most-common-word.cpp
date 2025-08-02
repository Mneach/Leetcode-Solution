class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Convert banned words into a hash set for O(1) lookups
        unordered_set<string> banned_words(banned.begin(), banned.end());
        unordered_map<string, int> word_counts;

        // Preprocess the paragraph: convert to lowercase and replace
        // non-alphabets with spaces
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
                  [](char c) { return isalpha(c) ? tolower(c) : ' '; });

        istringstream iss(paragraph);
        string current_word;
        string most_frequent_word;
        int highest_count = 0;

        // Process each word in the paragraph
        while (iss >> current_word) {
            // Skip banned words
            if (banned_words.count(current_word))
                continue;

            // Update word count and track the most frequent
            int current_count = ++word_counts[current_word];
            if (current_count > highest_count) {
                highest_count = current_count;
                most_frequent_word = current_word;
            }
        }

        return most_frequent_word;
    }
};