class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> answer;
        string temp = "";
        unordered_map<string, int> visited;

        for (auto c : s) {
            temp += c;

            if (visited.count(temp) == 0) {
                answer.push_back(temp);
                visited[temp]++;
                temp = "";
            }
        }

        return answer;
    }
};