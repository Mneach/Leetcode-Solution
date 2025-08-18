class Solution {
private:
    bool res = false;
    const double eps = 0.001;

    void helper(vector<double>& arr) {
        if (res) return;
        if (arr.size() == 1) {
            if (abs(arr[0] - 24.0) < eps)
                res = true;
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                vector<double> next;
                double p1 = arr[i], p2 = arr[j];
                next.insert(next.end(), {p1 + p2, p1 - p2, p2 - p1, p1 * p2});
                if (abs(p2) > eps) next.push_back(p1 / p2);
                if (abs(p1) > eps) next.push_back(p2 / p1);
                
                arr.erase(arr.begin() + i);
                arr.erase(arr.begin() + j);
                for (double n : next) {
                    arr.push_back(n);
                    helper(arr);
                    arr.pop_back();
                }
                arr.insert(arr.begin() + j, p2);
                arr.insert(arr.begin() + i, p1);
            }
        }
    }

public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr;
        for (int n : nums) arr.push_back((double)n);
        helper(arr);
        return res;
    }
};