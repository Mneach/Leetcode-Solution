class Solution {
public:
    
    bool checkUnique(string s){
        map<int,int> mp;
        
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        
        for(auto data : mp){
            if(data.second > 1){
                return false;
            }
        }
        
        return true;
    }
    
    void recursive(int &answer, int curr,vector<string> arr, string bucket){
        if(curr == arr.size()){
            return;
        }
        
        string temp = bucket + arr[curr];
        if(checkUnique(temp)){
            if(temp.length() > answer){
                answer = temp.length();
            }
            recursive(answer, curr + 1, arr, temp);
        }
        
        recursive(answer, curr + 1, arr, bucket);
        
    }
    
    int maxLength(vector<string>& arr) {
        
        int answer = 0;
        
        recursive(answer, 0, arr, "");
        
        return answer;
    }
};