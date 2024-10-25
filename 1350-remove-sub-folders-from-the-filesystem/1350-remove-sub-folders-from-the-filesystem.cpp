class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort folders to ensure parent folders come before subfolders
        sort(folder.begin(), folder.end());

        vector<string> result = {folder[0]}; // Start with the first folder

        for (int i = 1; i < folder.size(); ++i) {
            string lastFolderWithSlash = result.back() + '/';
            if (folder[i].substr(0, lastFolderWithSlash.size()) != lastFolderWithSlash) {
                result.push_back(folder[i]);
            }
        }

        return result;
    }
};
