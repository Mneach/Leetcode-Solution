class Solution {
public:
    
    bool comparePairs(const std::pair<string, int>& pair1, const std::pair<string, int>& pair2) {
        // If the first elements are equal, compare the second elements
        return pair1.second < pair2.second;
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        vector<pair<string, int>> arr;
        
        for(int i = 0; i < names.size(); i++){
            arr.push_back(make_pair(names[i], heights[i]));
        }
        
        sort(arr.begin(), arr.end(), [](const std::pair<string, int>& pair1, const std::pair<string, int>& pair2){
            return pair1.second > pair2.second;
        });
        
        vector<string> answer;
        
        for(int i = 0; i < arr.size(); i++){
            answer.push_back(arr[i].first);
        }
        
        return answer;
    }
};