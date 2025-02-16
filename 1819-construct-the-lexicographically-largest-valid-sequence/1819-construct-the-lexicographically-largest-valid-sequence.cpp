class Solution {
public:
    vector<int> answer;

    void printArray(vector<int> &bucket) {
        for (int i = 0; i < bucket.size(); i++) {
            cout << i << " " << bucket[i] << endl;
        }

        cout << endl;
    }

    void dfs(vector<int> &bucket, int index, int n, vector<bool> &visited) {
        // cout << index << endl;
        // printArray(bucket);
        // for (int i = 0; i < visited.size(); i++) {
        //     cout << i << " " << visited[i] << endl;
        // }
        // cout << endl;

        if (index == bucket.size()) {
            for (auto num : bucket) {
                answer.push_back(num);
            }
            return;
        }

        if (bucket[index] != -1) {
            dfs(bucket, index + 1, n, visited);
        }

        for (int i = n; i > 0; i--) {
            if (answer.size() > 0) return;
            if (visited[i]) continue;

            visited[i] = true;
            if (i == 1) {
                if (bucket[index] != -1) {
                    visited[i] = false;
                    dfs(bucket, index + 1, n , visited);
                } else {
                    bucket[index] = i;
                    dfs(bucket, index + 1, n, visited);
                    bucket[index] = -1;
                }
            } else {
                if (i + index >= bucket.size()) {
                    visited[i] = false;
                    return;
                } else if(bucket[index] != -1 || bucket[index + i] != -1) {
                    visited[i] = false;
                    continue;
                }
                bucket[index] = i;
                bucket[index + i] = i;
                dfs(bucket, index + 1, n , visited);
                bucket[index] = -1;
                bucket[index + i] = -1;
            }
            visited[i] = false;
        }
    }

    vector<int> constructDistancedSequence(int n) {

        if (n == 1) return {1};

        int totalData = ((n - 1) * 2) + 1;
        vector<bool> visited(n + 1, false);
        vector<int> bucket(totalData, -1);
        dfs(bucket, 0, n, visited);

        return answer;
    }
};