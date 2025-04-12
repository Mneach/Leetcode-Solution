/*

We can solve by using this solution
1. generate all palindrome and those data is divisible by x
2. using permutation formula to compute the answer

formula : N! / R1! x R2! ...
N = total digit
R1 = Repeted digit in that number

if repetetd digit is contain zero, we need to substract the formula

result = N! / R1! x R2! ...
reusltWithZero = N-1 / (R1 - 1)! x R2!
R1 = total zero

*/

class Solution {
public:

    long long answer = 0;

    void calculate(int n, vector<int>& arr, unordered_set<string>& visited, vector<long long> &factorial, int k) {
        string number = "";
        bool isContainZero = false;
        unordered_map<int,int> ump;

        for (auto data : arr) {
            if (data == 0) isContainZero = true;
            ump[data]++;
            char x = data + '0';
            number += x;
        }

        if (stol(number) % k != 0) return;

        sort(number.begin(), number.end());
        if (visited.count(number) > 0) return;
        visited.insert(number);

        long long divider = 1;
        for (auto data : ump) {
            divider *= factorial[data.second];
        }
        long long result = factorial[n] / divider;

        if (isContainZero) {
            divider = 1;
            for (auto data : ump) {
                if (data.first == 0 && data.second - 1 > 0) {
                    divider *= factorial[data.second - 1];
                } else {
                    divider *= factorial[data.second];
                }
            }
            result -= (factorial[n - 1] / divider);
        }

        answer += result;
    }

    void dfs(int index, int n, int k, vector<int>& arr, unordered_set<string>& visited, vector<long long> &factorial) {
        if (n % 2 == 0 && index == n / 2) {
            calculate(n, arr, visited, factorial, k);
        } else if(n % 2 == 1 && index > n / 2) {
            calculate(n, arr, visited, factorial, k);
        } else {
            int start = 0;
            if (index == 0) start = 1;

            for(int i = start; i <= 9; i++) {
                arr[index] = i;
                arr[n - index - 1] = i;
                dfs(index + 1, n, k, arr, visited, factorial);
            }
        }
    }

    long long countGoodIntegers(int n, int k) {
        unordered_set<string> visited;
        vector<int> arr(n, 0);
        vector<long long> factorial(11, 0);
        factorial[1] = 1;
        factorial[2] = 2;

        for (int i = 3; i < factorial.size(); i++) {
            factorial[i] = i * factorial[i - 1];
        }

        dfs(0, n, k, arr, visited, factorial);

        return answer;
    }
};