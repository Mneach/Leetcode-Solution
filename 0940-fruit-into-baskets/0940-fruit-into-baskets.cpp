class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> bucket;

        int left, right;
        left = right = 0;

        while (right < fruits.size()) {
            bucket[fruits[right]]++;

            if (bucket.size() > 2) {
                bucket[fruits[left]]--;
                if (bucket[fruits[left]] == 0) {
                    bucket.erase(fruits[left]);
                }
                left++;
            }
            right++;
        }

        return right - left;
    }
};