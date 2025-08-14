class Solution {
public:
    string largestGoodInteger(string num) {
        
        vector<string> bucket;
        int counter = 0;
        for(int i = 0; i < num.size() - 2; i++){
            
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2]){
                bucket.push_back(num.substr(i, 3));
            }
            
            
        }
        
        sort(bucket.begin(), bucket.end());
        
        return bucket.empty() ? "": bucket[bucket.size() - 1];
    }
};