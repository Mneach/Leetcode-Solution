class Solution {
public:

    void recursive(vector<vector<int>> &answer, vector<int> current, int n, int k, int start){
        if(current.size() == k){
            answer.push_back(current);
            return;
        }

        for(int i = start; i <= n; i++){
            current.push_back(i);
            recursive(answer, current, n, k, i + 1);
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        if(n == 1 && k == 1) return {{1}};

        vector<vector<int>> answer;
        vector<int> current;

        recursive(answer, current, n , k, 1);

        return answer;
    }
};