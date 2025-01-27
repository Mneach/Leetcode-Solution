class Solution {
public:

    unordered_set<int> dfs(vector<vector<int>> &adjList, int source, vector<unordered_set<int>> &bucket) {
        if (bucket[source].size() > 0) {
            return bucket[source];
        }

        bucket[source].insert(source);
        for (auto node : adjList[source]) {
            unordered_set<int> temp = dfs(adjList, node, bucket);
            bucket[source].insert(temp.begin(), temp.end());
        }

        return bucket[source];
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> answer;
        vector<vector<int>> adjList(numCourses);

        for (auto data : prerequisites) {
            int source = data[0];
            int dest = data[1];

            adjList[source].push_back(dest);
        }

        // fill the bucket
        vector<unordered_set<int>> bucket(numCourses);
        for (int i = 0; i < adjList.size(); i++) {
            dfs(adjList, i, bucket);
        }

        // for (int i = 0; i < bucket.size(); i++) {
        //     cout << "node : = " << i << endl;
        //     for (auto data : bucket[i]) {
        //         cout << data << " ";
        //     }
        //     cout << endl;
        // }

        for (auto data : queries) {
            int source = data[0];
            int dest = data[1];

            bool find = bucket[source].find(dest) != bucket[source].end();

            answer.push_back(find);
        }

        return answer;
    }
};