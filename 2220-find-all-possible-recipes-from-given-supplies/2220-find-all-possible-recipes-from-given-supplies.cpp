class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> graph;
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> result;

        // Build graph and in-degree count
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
        }

        // Initialize queue with available supplies
        for (const string& supply : supplies) {
            q.push(supply);
        }

        // Process available supplies and derived recipes
        while (!q.empty()) {
            string item = q.front(); q.pop();
            if (inDegree.count(item)) result.push_back(item);

            for (const string& dependent : graph[item]) {
                if (--inDegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }

        return result;
    }
};
