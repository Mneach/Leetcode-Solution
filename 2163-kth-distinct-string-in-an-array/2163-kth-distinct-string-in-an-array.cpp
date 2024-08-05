class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> visited;
        vector<string> temp;
        int count = 0;
        
        for(auto data : arr){
            if(visited[data] <= 0){
                temp.push_back(data);
            }
            visited[data]++;
        }

        for(auto data : temp){
            if(visited[data] == 1){
                count++;
            }

            if(count == k){
                return data;
            }
        }

        return "";
    }
};