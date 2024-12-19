class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       
       stack<int> mst;

       for (int i = 0; i < arr.size(); i++) {
            if (mst.empty() || arr[i] > mst.top()) mst.push(arr[i]);
            else {
                int top = mst.top();

                while (mst.size() > 0 && arr[i] < mst.top()) {
                    mst.pop();
                }

                mst.push(top);
            }
       }

       return mst.size();
    }
};