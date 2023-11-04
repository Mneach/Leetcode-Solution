class Solution {
public:
    string addBinary(string a, string b) {
        
        string tempA = "";
        string tempB = "";
        int sizeA = a.length();
        int sizeB = b.length();
        
        if(sizeA > sizeB){
            for(int i = 0; i < sizeA - sizeB; i++){
                tempB += '0';
            }
        }
        
        if(sizeA < sizeB){
            for(int i = 0; i < sizeB - sizeA; i++){
                tempA += '0';
            }
        }
        
        tempA += a;
        tempB += b;
        
        cout << tempA << " " << tempB << endl;
        
        char carry = ' ';
        
        for(int i = tempA.size() - 1; i >= 0; i--){
            if(tempA[i] == '1' && tempB[i] == '1'){
                if(carry == '1'){
                    carry = '1';
                    tempA[i] = '1';
                }else{
                    carry = '1';
                    tempA[i] = '0';
                }
            }else if(tempA[i] == '1' && tempB[i] == '0'){
                if(carry == '1'){
                    tempA[i] = '0';
                    carry = '1';
                }else{
                    tempA[i] = '1';
                }
            }else if(tempA[i] == '0' && tempB[i] == '1'){
                if(carry == '1'){
                    tempA[i] = '0';
                    carry = '1';
                }else{
                    tempA[i] = '1';
                }
            }else if(carry == '1'){
                tempA[i] = '1';
                carry = '0';
            }
        }
        
        
        if(carry == '1'){
            return "1" + tempA;
        }else{
            return tempA;
        }
    }
};