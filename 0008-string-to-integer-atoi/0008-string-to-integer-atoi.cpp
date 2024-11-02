class Solution {
public:
    int myAtoi(string s) {
        int size = s.length();

        double num = 0;
        int index = 0;

        while(s[index] == ' '){
            index++;
        }

        bool isPositive = s[index] == '+';
        bool isNegative = s[index] == '-';

        if(isPositive) index++;
        if(isNegative) index++;

        while(index < size){
            if(!(s[index] >= '0' && s[index] <= '9')){
                break;
            }
            int current = (s[index] - '0');
            num = (num * 10) + current;
            index++;
        }

        if(isNegative) num *= -1;

        if(num <= INT_MIN) num = INT_MIN;
        else if(num >= INT_MAX) num = INT_MAX;

        int answer = int(num);

        return answer;
    }
};