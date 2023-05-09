class Solution {
public:
    bool isPalindrome(string s) {
            string reverseString = "";

            int length = s.length();

            for (int i = 0; i < length; i++)
            {
                if(tolower(s[i]) >= 'a'  && tolower(s[i]) <= 'z' && s[i] != ' '){
                    reverseString.push_back(tolower(s[i]));
                }else if(s[i] >= '0' && s[i] <= '9'){
                    reverseString.push_back(s[i]);
                }
            }
            
            string tempString = reverseString;
            reverse(reverseString.begin(), reverseString.end());

            cout << tempString << " " << reverseString << endl;
        
            return tempString == reverseString;
        }
};