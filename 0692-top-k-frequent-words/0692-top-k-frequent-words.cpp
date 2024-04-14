class Data {
public:
    int total;
    std::string word;

    Data(int t, std::string w) : total(t), word(std::move(w)) {}

     bool operator<(const Data& other) const {
        if (total == other.total) {
            return word > other.word;
        } else {
            return total < other.total;
        }
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        priority_queue<Data> pq;
        
        for(auto word : words){
            mp[word]++;
        }
        
        for(auto word : mp){
            Data data(word.second, word.first);
            pq.push(data);
        }
        
        vector<string> answer;
        while(k--){
            answer.push_back(pq.top().word);
            pq.pop();
        }
        
        return answer;
    }
};