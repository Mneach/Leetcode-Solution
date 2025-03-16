class Compare {
public:
    bool operator()(vector<long long> &first, vector<long long> &second){
        return first[0] > second[0];
    }
};

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        unordered_map<int,int> count;
        priority_queue<vector<long long>, vector<vector<long long>>, Compare> pq;

        for (auto rank : ranks) {
            count[rank] += 1;
        }

        for (auto data : count) {
            int rank = data.first;
            int mechanics = data.second;
            pq.push({rank, rank, 1, mechanics});
        }

        long long time = 0;
        while (cars > 0) {
            vector<long long> data = pq.top();
            pq.pop();
            time = data[0];
            long long rank = data[1];
            long long n = data[2];
            long long mechanics = data[3];
            n += 1;
            cars -= mechanics;

            pq.push({rank * n * n, rank, n, mechanics});
        }

        return time;
    }
};