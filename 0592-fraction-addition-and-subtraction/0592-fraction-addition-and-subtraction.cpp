class Solution {
public:

    int getNumber(string expression, int &index, vector<char> &symbols){
        string temp = "";

        while(index < expression.size()){
            if(expression[index] == '/' || expression[index] == '+' || expression[index] == '-'){
                if(expression[index] != '/'){
                    symbols.push_back(expression[index]);
                }
                index++;
                break;
            }

            temp += expression[index];
            index++;
        }
        int res = temp.size() == 0 ? 1 : stoi(temp);

        return res;
    }

    string fractionAddition(string expression) {
        
        int answer = 0;
        vector<pair<int,int>> vp;
        vector<char> symbols;
        
        int i = 0;
        int first, second;
        first = second = 0;

        while(i < expression.size()){
            if(expression[i] == '-'){
                i++;
                first = getNumber(expression, i, symbols) * -1;
            }else{
                first = getNumber(expression, i, symbols);
            }

            if(expression[i] == '-'){
                i++;
                second = getNumber(expression, i, symbols) * -1;
            }else{
                second = getNumber(expression, i, symbols);
            }
            
            vp.push_back({first, second});
        }

        if(vp.size() == 1){
            return expression;
        }

        // get gcd
        int divisor = 0;
        for(int i = 0; i < vp.size(); i++){
            if(i == 0){
                divisor = vp[i].second;
            }else{
                divisor = lcm(divisor, vp[i].second);
            }
        }

        
        
        for(int i = 0; i < vp.size() - 1; i++){
            int first = 0;

            if(i == 0){
                first = vp[i].first * (divisor / vp[i].second);
            }else{
                first = vp[i].first;
            }
            int second = vp[i + 1].first * (divisor / vp[i + 1].second);
            char symbol = symbols[i];

            if(symbol == '+'){
                answer = (first + second);
            }else{
                answer = (first - second);
            }

            vp[i + 1].first = answer;
            cout << answer << endl;
        }

        if(answer != 0){
            int temp = gcd(divisor, answer);
            answer /= temp;
            divisor /= temp;
        }

        string result = "";
        result += to_string(answer);
        result += "/";
        result += to_string(divisor);

        if(result[0] == '0') result[2] = '1';

        return result;
    }
};