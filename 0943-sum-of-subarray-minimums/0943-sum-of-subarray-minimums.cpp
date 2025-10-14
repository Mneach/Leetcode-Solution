/*

How to solve the problem

# Using stack
1. create a class Data
   - int number
   - int total
   - getter functions
   - int getResult()
     - return number * total
2. initialize variables
   - stack<Data> st
   - result = 0
   - tempResult = 0
3. loop from the first index of array until last index of array
   - if stack is empty
     - push {arr[i], 1} to the stack
   - else if arr[i] > st.top().getNumber()
     - result += tempResult + arr[i]
     - tempResult += arr[i]
     - push {arr[i], 1} to the stack
   - else
     - total = 0
     - currentNumber = nums[i]
     - while st.size() > 0 && number < st.top().getNumber()
       - total += st.top().getTotal();
       - tempResult -= st.top().getResult()
       - st.pop()
     - st.push({currentNumber, total})
     - tempResult += st.top().getResult()
     - result += tempResult
4. return the result

Time Complexity : O(N + M) = O(N)
N -> size of array
M -> size of stack

Memory Complexity : O(M)
M -> size of stack

*/

class Data {
private:
    int number;
    int total;
public:
    Data(int number, int total) {
        this -> number = number;
        this -> total = total;
    }

    int getNumber() {
        return this -> number;
    }

    int getTotal() {
        return this -> total;
    }

    long long getResult() {
        return 1LL * this -> number * this -> total;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        stack<Data> st;
        long long result = 0;
        long long tempResult = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (st.empty()) {
                result = arr[i];
                tempResult = arr[i];
                st.push({arr[i], 1});
            } else if (arr[i] > st.top().getNumber()) {
                result = ((result % mod) + (tempResult + arr[i]) % mod) % mod;
                tempResult = (tempResult + arr[i]) % mod;
                st.push({arr[i], 1});
            } else {
                int currentNumber = arr[i];
                int total = 1;

                while (st.size() > 0 && currentNumber < st.top().getNumber()) {
                    total += st.top().getTotal();
                    tempResult -= st.top().getResult();
                    st.pop();
                }

                st.push({currentNumber, total});
                tempResult = (tempResult + st.top().getResult()) % mod;
                result = (result + tempResult) % mod;
            }
        }

        return result;
    }
};