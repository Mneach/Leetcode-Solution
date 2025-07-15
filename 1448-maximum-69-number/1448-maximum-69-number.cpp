class Solution {
public:
    int maximum69Number (int num) {
        int position = -1;
        int index = 0;
        int temp = num;

        while (temp > 0) {
            int mod = temp % 10;
            temp /= 10;

            if (mod == 6) position = index;
            index++;
        }

        if (position == -1) return num;

        return (num - (6 * pow(10, position))) + (9 * pow(10, position));
    }
};