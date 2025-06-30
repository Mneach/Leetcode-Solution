class Solution {
public:
    int findLHS(vector<int>& nums) {
        int answer = 0;
        int current = 0;
        int next = 0;
        bool isCurrent = true;

        sort(nums.begin(), nums.end());

        for (auto num : nums) {
            cout << num << " ";
        }
        cout << endl;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                if (isCurrent) current++; 
                else next++;
            } else {
                if (isCurrent) current++;
                else next++;

                cout << i << " " << current << " " << next << " " << isCurrent << endl;

                if (abs(nums[i + 1] - nums[i]) == 1) {
                    if (isCurrent == true) {
                        isCurrent = false;
                        continue;
                    }
                    answer = max(answer, current + next);
                    current = next;
                    next = 0;
                } else {
                    if (current != 0 && next != 0) {
                        answer = max(answer, current + next);
                        isCurrent = true;
                        current = 0;
                    } else if (isCurrent && current != 0 && next == 0) {
                        if (abs(nums[i + 1] - nums[i]) == 1) {
                            isCurrent = false;
                        }
                        current = 0;
                    }
                    next = 0;
                }
            }
        }

        if (nums.size() > 1 && isCurrent == false) {
            if (nums[nums.size() - 1] == nums[nums.size() - 2]) next++;
            else if (nums[nums.size() - 1] - nums[nums.size() - 2] == 1) next++;
        }

        if (current != 0 && next != 0) {
            answer = max(answer, current + next);
        }

        return answer;
    }
};