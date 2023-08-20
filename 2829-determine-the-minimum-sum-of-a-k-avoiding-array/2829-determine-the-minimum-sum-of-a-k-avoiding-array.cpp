class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> bucket;
        int answer = 0;
        int index = 0;
        int current = 0;
        while(index < n){
            bool valid = true;
            current++;
            int reminder = k - current;
            
            if(find(bucket.begin(), bucket.end(), reminder) != bucket.end()) valid = false;
            
            if(valid) {
                //cout << current << endl;
                answer += current;
                index++;
            }   
            bucket.push_back(reminder);
            bucket.push_back(current);
        }
        
        return answer;
    }
};