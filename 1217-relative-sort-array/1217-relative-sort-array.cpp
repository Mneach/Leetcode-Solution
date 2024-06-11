class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> ump;
        vector<int> answer;

        for(int i = 0; i < arr1.size(); i++){
            ump[arr1[i]]++;
        }


        for(auto number : arr2){
            int total = ump[number];
            ump[number] = -1;

            for(int i = 0; i < total; i++) answer.push_back(number);
        }

        for(auto data : ump){
            if(data.second != -1) {
                for(int i = 0; i < data.second; i++) answer.push_back(data.first);
            }
        }

        return answer;
    }
};