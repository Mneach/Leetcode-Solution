class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> answer(nums.size(), -1);
        stack<int> st;

        for (int i = 0; i < nums.size() * 2; i++) {
            while(st.empty() == false && nums[st.top()] < nums[i % nums.size()]) {
                int index = st.top();
                st.pop();

                answer[index % nums.size()] = nums[i % nums.size()];
            }

            if (answer[i % nums.size()] == -1) {
                st.push(i % nums.size()); 
            }
        }

        return answer;
    }
};