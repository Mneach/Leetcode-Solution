class Solution {
public:
    
    vector<int> number;
    int count = 0;
    
    Solution(vector<int>& w) {
        for(int i = 0; i < w.size(); i++){
            if(i == 0){
                number.push_back(w[i]);
            }else{
                number.push_back(number[i - 1] + w[i]);
            }
        }
    }
    
    int pickIndex() {
        double random = (double) rand() / RAND_MAX;
        double find = random * number[number.size() - 1];
        return lower_bound(number.begin(), number.end(), find) - number.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */