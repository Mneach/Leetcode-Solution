class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> answer;

        for(int i = 1; i < arr.size(); i++){
            arr[i] ^= arr[i - 1];
        }

        for(auto query : queries){
            
            int start = query[0];
            int end = query[1];

            if(start == 0){
                answer.push_back(arr[end]);
            }else{
                answer.push_back(arr[start - 1] ^ arr[end]);
            }
        }

        return answer;
    }
};