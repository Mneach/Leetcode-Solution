class Solution {
public:

    string invert(string s){

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                s[i] = '1';
            }else{
                s[i] = '0';
            }
        }

        return s;
    }

    char findKthBit(int n, int k) {
        if(n == 1){
            return '0';
        }
        
        string current = "";
        string prev = "0";

        for(int i = 1; i < n; i++){

            string reverseString = prev;
            reverse(reverseString.begin(), reverseString.end());
            current = prev + "1" + invert(reverseString);
            prev = current;
        }

        cout << current << endl;

        return current[k - 1];
    }
};