class Solution {
public:
    
    bool check(char x){
        string vowels = "aiueo";

        return vowels.find(x) != string::npos ? true : false;
    }
    
    int beautifulSubstrings(string s, int k) {

        unordered_map<int,vector<int>> ump;
        ump[0].push_back(0);
        int hashTableIndex = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(check(s[i])){
                hashTableIndex++;
            }else{
                hashTableIndex--;
            }

            ump[hashTableIndex].push_back(i + 1);
        }

        int x = 1;
        while(x <= k && x * x % k){
            x++;
        }

        // x * 2 becuase the length of vowels must be equals to consonant
        x *= 2;

        int answer = 0;

        for(auto data : ump){
            vector<int> res(x, 0);
            for(auto vecNumber : data.second){
                answer += res[vecNumber % x]++;
            }
        }

        return answer;
    
    }
};