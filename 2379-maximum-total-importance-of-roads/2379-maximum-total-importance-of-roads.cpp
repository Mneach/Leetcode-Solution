class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> bucket(n, 0);

        for(auto edge : roads){
            bucket[edge[0]]++;
            bucket[edge[1]]++;
        }

        sort(bucket.begin(), bucket.end());

        long long temp = 1;
        long long answer = 0;

        for(auto data : bucket){
            answer += (temp * data);
            temp++;
        }

        return answer;
    }
};