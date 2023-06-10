class Solution {
public:
    bool isFascinating(int n) {
        
        string s = to_string(n) + to_string(n * 2) + to_string(n * 3);
        
        cout << s << endl;
        
        vector<int> arr(10, 0);
        
        for(int i = 0; i < s.length(); i++){
            arr[s[i] - '0']++;
        }
        
        for(int i = 0; i < 10; i++){
            if(i == 0 && arr[i] != 0) return false;
            else if(arr[i] > 1) return false; 
        }
        
        return true;
    }
};