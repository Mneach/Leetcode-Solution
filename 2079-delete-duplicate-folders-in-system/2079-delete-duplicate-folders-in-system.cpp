struct TrieNode {
    string serial;  // Serialized representation of subtree
    unordered_map<string, TrieNode*> children;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Build the trie structure from all paths
        TrieNode* root = buildTrie(paths);
        
        // Calculate serials for all nodes and track frequencies
        unordered_map<string, int> serialFreq;
        calculateSerials(root, serialFreq);
        
        // Collect all unique paths
        vector<vector<string>> result;
        vector<string> currentPath;
        collectUniquePaths(root, serialFreq, currentPath, result);
        
        return result;
    }

private:
    // Helper function to build the trie from paths
    TrieNode* buildTrie(const vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for (const auto& path : paths) {
            TrieNode* current = root;
            for (const string& folder : path) {
                if (current->children.find(folder) == current->children.end()) {
                    current->children[folder] = new TrieNode();
                }
                current = current->children[folder];
            }
        }
        return root;
    }

    // Post-order traversal to calculate serials
    void calculateSerials(TrieNode* node, unordered_map<string, int>& serialFreq) {
        if (node->children.empty()) return;

        vector<string> childSerials;
        for (auto& [folder, child] : node->children) {
            calculateSerials(child, serialFreq);
            childSerials.push_back(folder + "(" + child->serial + ")");
        }

        sort(childSerials.begin(), childSerials.end());
        for (string& s : childSerials) {
            node->serial += move(s);
        }
        serialFreq[node->serial]++;
    }

    // DFS to collect unique paths
    void collectUniquePaths(TrieNode* node, 
                          const unordered_map<string, int>& serialFreq,
                          vector<string>& currentPath,
                          vector<vector<string>>& result) {
        // Skip if this is a duplicate subtree
        if (!node->serial.empty() && serialFreq.at(node->serial) > 1) {
            return;
        }
        
        // Add current path to results if not empty
        if (!currentPath.empty()) {
            result.push_back(currentPath);
        }
        
        // Recurse through children
        for (auto& [folder, child] : node->children) {
            currentPath.push_back(folder);
            collectUniquePaths(child, serialFreq, currentPath, result);
            currentPath.pop_back();
        }
    }
};