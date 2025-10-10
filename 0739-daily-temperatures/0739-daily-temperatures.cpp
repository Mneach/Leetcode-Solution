/*

How to solve the problems 
1. initialize class
   - int temperature
   - int index
2. initialize variables
   - stack<Data> st
   - vector<int> results with default size = temperatures.size() and default value = 0
3. loop from the first index of temperatures until last index of temperatures
   - while (st.size() > 0 && st.top().temperature < temperatures[i]) 
     - calculate the distance between st.top().index with current index 
     - put the distance value into the answers -> answers[st.top().index] = i - st.top().index
     - remove the data from the stack
   - push temperatures[i] into the stack
4. return the results array

Time Complexity : O(N)
N -> size of temperatures

Memory Complexity : O(N)
N -> size of temperatures

*/

class Data {
private:
    int temperature;
    int index;
public:
    Data(int temperature, int index) {
        this -> temperature = temperature;
        this -> index = index;
    }

    int getTemperature() {
        return this -> temperature;
    }

    int getIndex() {
        return this -> index;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<Data> st;        
        vector<int> results(temperatures.size(), 0);

        for (int i = 0 ; i < temperatures.size(); i++) {
            while (st.size() > 0 && st.top().getTemperature() < temperatures[i]) {
                int distance = i - st.top().getIndex();
                results[st.top().getIndex()] = distance;
                st.pop();
            }

            st.push({temperatures[i], i});
        }

        return results;
    }
};