class Solution {
public:
    long long minimumSteps(string s) {
        long long answer = 0;

        int left = 0;

        while(left < s.length() && s[left] == '0'){
            left++;
        }

        for(int right = left + 1; right < s.length(); right++){
            if(s[right] == '1') continue;
            answer += right - left;
            left++;
        }
        
        return answer;
    }
};