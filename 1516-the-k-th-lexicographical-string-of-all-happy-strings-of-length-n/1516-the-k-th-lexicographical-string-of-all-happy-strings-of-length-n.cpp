class Solution {
public:

    void dfs(vector<string> &bucket, int n, int k, string current){
        if(current.length() == n){
            bucket.push_back(current);
            return;
        }

        for(int i = 0; i < 3; i++){
            char x = 'a' + i;

            if(current.length() > 0 && current[current.length() - 1] == x) continue;

            dfs(bucket, n , k , current + x);
        }
    }

    string getHappyString(int n, int k) {
        vector<string> bucket;

        dfs(bucket, n , k, "");

        for(auto data : bucket){
            cout << data << endl;
        }

        if(k > bucket.size()) return "";
        
        return bucket[k - 1];      
    }
};