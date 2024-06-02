class Solution {
public:

    void dfs(vector<int> &answer, set<int> &bucket, int n, int start){
        for(int i = 0; i < n; i++){
            int next = start ^ (1 << i);

            if(!bucket.contains(next)){
                answer.push_back(next);
                bucket.insert(next);
                dfs(answer, bucket, n , next);
            }
        }
    }

    vector<int> circularPermutation(int n, int start) {
        vector<int> answer;
        set<int> bucket;

        answer.push_back(start);
        bucket.insert(start);

        dfs(answer, bucket, n , start);

        return answer;
    }
};