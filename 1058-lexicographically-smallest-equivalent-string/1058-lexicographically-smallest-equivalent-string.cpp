class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        initializeParentArray();
        
        // Union all equivalent characters
        for (size_t i = 0; i < s1.size(); ++i) {
            unionSets(s1[i] - 'a', s2[i] - 'a');
        }
        
        // Build the result string
        for (char& c : baseStr) {
            c = findParent(c - 'a') + 'a';
        }
        
        return baseStr;
    }

private:
    static const int ALPHABET_SIZE = 26;
    int parent[ALPHABET_SIZE];
    
    void initializeParentArray() {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            parent[i] = -1;
        }
    }
    
    int findParent(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = findParent(parent[x]); // Path compression
    }
    
    void unionSets(int x, int y) {
        x = findParent(x);
        y = findParent(y);
        
        if (x != y) {
            // Always point the larger parent to the smaller one
            parent[max(x, y)] = min(x, y);
        }
    }
};