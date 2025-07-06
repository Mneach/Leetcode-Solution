class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> bucket1;
        unordered_map<int, vector<string>> answerBucket;

        for (int i = 0; i < list1.size(); i++) {
            bucket1[list1[i]] = i;
        }

        for (int i = 0; i < list2.size(); i++) {
            string word = list2[i];

            if (bucket1.count(word) > 0) {
                int currentIndex = i;
                int bucket1Index = bucket1[word];

                answerBucket[currentIndex + bucket1Index].push_back(word);
            }
        }

        vector<string> answer;
        int current = INT_MAX;

        for (auto data : answerBucket) {
            int sumIndex = data.first;
            vector<string> currentData = data.second;

            if (current > sumIndex) {
                answer = currentData;
                current = sumIndex;
            }
        }

        return answer;
    }
};