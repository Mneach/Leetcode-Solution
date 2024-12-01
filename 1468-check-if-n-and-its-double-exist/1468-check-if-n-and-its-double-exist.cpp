class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<long long int,int> ump;

        for (auto number : arr) {
            long long curr = number * 2;
            
            if (ump[curr * 2] > 0 || ump[number] > 0) return true;

            ump[curr]++;
        }

        return false;
    }
};