/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

/*

How to solve the problem

# Using stack
1. put all of the data from nestedList to stack
2. next functions
   - int result = stack.top()
   - stack.pop()
   - return result
3. has next functions
   - while stack is not empty
     - get data from top of the stack
     - if the current data == integer, return true
     - loop from the last index until first index
       - push all of the data into the stack
     - return true
   
Time Complexity : O(N)
N -> size of nestedList

Memory Complexity : O (M)
M -> size of stack


*/

class NestedIterator {
private:
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }
    
    int next() {
        int result = st.top().getInteger();
        st.pop();

        return result;
    }
    
    bool hasNext() {
        while (st.size() > 0) {
            NestedInteger data = st.top();

            if (data.isInteger()) {
                return true;
            }

            st.pop();
            vector<NestedInteger> dataList = data.getList();
            for (int i = dataList.size() - 1; i >= 0; i--) {
                st.push(dataList[i]);
            }
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */