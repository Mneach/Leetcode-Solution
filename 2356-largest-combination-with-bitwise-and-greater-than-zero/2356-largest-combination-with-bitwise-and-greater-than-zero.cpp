class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int answer = 0;
        int maximum = *max_element(candidates.begin(), candidates.end());

        int start = 1;
        while(start <= maximum){
            int temp = 0;
            for(int i = 0; i < candidates.size(); i++){
                int number = candidates[i]; 
                // cout << start << " " << number << " " << (number & start) << " " << temp << endl;
                if((number & start) > 0) temp++;
            }
            start *= 2;
            answer = max(answer, temp);
        }

        return answer;
    }
};