class Solution
{
    public:
        int findJudge(int N, vector<vector < int>> &trust)
        {
            if (trust.size() < N - 1)
            {
                return -1;
            }

            std::vector<int> indegrees(N + 1, 0);
            std::vector<int> outdegrees(N + 1, 0);

            for (const auto &relation: trust)
            {
                outdegrees[relation[0]]++;
                indegrees[relation[1]]++;
            }

            for (int i = 1; i <= N; i++)
            {
                if (indegrees[i] == N - 1 && outdegrees[i] == 0)
                {
                    return i;
                }
            }
            return -1;
        }
};