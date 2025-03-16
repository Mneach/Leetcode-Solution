class Solution {
public:

    void recursive(vector<int>& candidates, vector<vector<int>> &answer, int target, int current, int index, vector<int> &temp){

        cout << current << endl;
        if(current == target){
            answer.push_back(temp);
            return;
        }

        if(current > target) return;

        if(index >= candidates.size()) return;

        // add current
        temp.push_back(candidates[index]);
        recursive(candidates, answer, target, current + candidates[index], index + 1, temp);
        temp.pop_back();

        // skip current
        while(index + 1 < candidates.size() && candidates[index] == candidates[index + 1]){
            index++;
        }
        
        recursive(candidates, answer, target, current, index + 1, temp);

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        recursive(candidates, answer, target, 0, 0, temp);

        return answer;
    }
};