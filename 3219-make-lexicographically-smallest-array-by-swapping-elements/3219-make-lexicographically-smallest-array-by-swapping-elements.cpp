class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> answer;
        vector<int> bucket;
        vector<queue<int>> arr;
        unordered_map<int,int> ump;

        for (auto num : nums) bucket.push_back(num);

        sort(bucket.begin(), bucket.end());

        for (auto num : bucket) {
            if (arr.size() == 0) {
                queue<int> temp;
                temp.push(num);
                arr.push_back(temp);
            } else {
                int lastNumber = arr[arr.size() - 1].back();

                if (abs(num - lastNumber) > limit) {
                    queue<int> temp;
                    temp.push(num);
                    arr.push_back(temp);
                } else {
                    arr[arr.size() - 1].push(num);
                }
            }

            ump[num] = arr.size() - 1;
        }

        for (auto num : nums) {
            int groupNumber = ump[num];
            int result = arr[groupNumber].front();
            arr[groupNumber].pop();

            answer.push_back(result);
        }

        return answer;
    }
};