class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> bucket;
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i < word.size(); i++){
            bucket[word[i]]++;
        }

        for(auto data : bucket){
            pq.push({data.second, data.first});
        }

        int count = 1;
        int answer = 0;
        int currentNumber = 2;

        while(pq.empty() == false){
            auto data = pq.top();
            pq.pop();
            answer += (count * data.first);
            currentNumber++;

            if(currentNumber == 10){
                currentNumber = 2;
                count++;
            }
        }

        return answer;
    }
};