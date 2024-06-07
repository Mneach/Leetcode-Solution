class Solution {
public:

    string getRoot(string s, vector<string>& dictionary){
        for(auto data : dictionary){
            if(s.find(data) != string::npos){
                s = data;
                break;
            }
        }

        return s;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        unordered_map<string,int> ump;

        for(auto data : dictionary) ump[data]++;

        string res = "";

        string temp = "";
        bool flag = false;
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == ' '){
                if(flag == false){
                    res += temp + ' ';
                }else{
                    res += ' ';
                }

                temp = "";
                flag = false;
            }else if(flag == false){
                temp += sentence[i];

                if(ump[temp] > 0){
                    res += temp;
                    flag = true;
                }
            }
        }

        cout << temp << endl;

        if(flag == false){
            res += temp;
        }

        return res;
    }
};