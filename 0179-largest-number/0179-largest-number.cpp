class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> temp;

        for(auto data : nums){
            temp.push_back(to_string(data));
        }

        sort(temp.begin(), temp.end(),[](string &first, string &second){
            return first + second > second + first;
        });

        string answer = "";
        bool zero = true;
        for(auto data : temp) {
            if(stoi(data) > 0){
                zero = false;
            }
            answer += data;
        }

        
        if(zero){
            return "0";
        }else{
            return answer;
        }
    }
};