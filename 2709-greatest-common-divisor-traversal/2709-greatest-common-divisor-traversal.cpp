#include <vector>
#include <unordered_set>
#include <cmath>

class DSU
{
    public:
        std::vector<int> dsu;
    std::vector<int> size;

    DSU(int N)
    {
        dsu.resize(N + 1);
        size.resize(N + 1);
        for (int i = 0; i <= N; i++)
        {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));
    }
    void merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy)
        {
            return;
        }
        if (size[fx] > size[fy])
        {
            std::swap(fx, fy);
        }
        dsu[fx] = fy;
        size[fy] += size[fx];
    }
};

class Solution
{
    public:
        bool canTraverseAllPairs(std::vector<int> &nums)
        {
            int MAX = 100000;
            int N = nums.size();
            std::unordered_set<int> has(nums.begin(), nums.end());

            if (N == 1)
            {
                return true;
            }
            if (has.find(1) != has.end())
            {
                return false;
            }

            std::vector<int> sieve(MAX + 1, 0);
            for (int d = 2; d <= MAX; d++)
            {
                if (sieve[d] == 0)
                {
                    for (int v = d; v <= MAX; v += d)
                    {
                        sieve[v] = d;
                    }
                }
            }

            DSU unionFind(2 *MAX + 1);
            for (int x: nums)
            {
                int val = x;
                while (val > 1)
                {
                    int prime = sieve[val];
                    int root = prime + MAX;
                    if (unionFind.find(root) != unionFind.find(x))
                    {
                        unionFind.merge(root, x);
                    }
                    while (val % prime == 0)
                    {
                        val /= prime;
                    }
                }
            }

            int cnt = 0;
            for (int i = 2; i <= MAX; i++)
            {
                if (has.find(i) != has.end() && unionFind.find(i) == i)
                {
                    cnt++;
                }
            }
            return cnt == 1;
        }
};