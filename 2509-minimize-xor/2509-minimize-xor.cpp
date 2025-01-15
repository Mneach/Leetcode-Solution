class Solution {
public:

    string convertTo32Bit(int num) {

        string result = "";

        while (num > 0) {
            if (num % 2 == 0) result += '0';
            else result += '1';
            num /= 2;
        }

        reverse(result.begin(), result.end());

        string temp = "";
        for (int i = 0; i < 33 - result.size(); i++) {
            temp += '0';
        }

        return temp + result;
    }

    int getTotalBit(string bitNum) {
        int result = 0;

        for(int i = 0; i < bitNum.length(); i++) {
            if (bitNum[i] == '1') result++;
        }

        return result;
    }

    int convertToNumber(string bit) {
        int result = 0;
        
        int index = 0;
        for(int i = bit.length() - 1; i >= 0; i--) {
            if (bit[i] == '1') {
                result += pow(2, index);
            }

            index++;
        }

        return result;
    }

    int minimizeXor(int num1, int num2) {
        string bitsNum1 = convertTo32Bit(num1);
        string bitsNum2 = convertTo32Bit(num2);

        cout << bitsNum1 << endl;
        cout << bitsNum2 << endl;

        int totalBitNum1 = getTotalBit(bitsNum1);
        int totalBitNum2 = getTotalBit(bitsNum2);

        if (totalBitNum2 >= totalBitNum1) {
            totalBitNum2 -= totalBitNum1;

            for (int i = bitsNum1.length() - 1; i >= 0; i--) {
                if(totalBitNum2 == 0) break;
                
                if (bitsNum1[i] == '1') continue;
                else {
                    bitsNum1[i] = '1';
                    totalBitNum2--;
                }
            }

            return convertToNumber(bitsNum1);
        }else {
            int totalProcess = totalBitNum1 - totalBitNum2;
            for (int i = bitsNum1.length() - 1; i >= 0; i--) {
                if (totalProcess == 0) break;

                if (bitsNum1[i] == '1') {
                    bitsNum1[i] = '0';
                    totalProcess--;
                }
            }

            return convertToNumber(bitsNum1);
        }
    }
};