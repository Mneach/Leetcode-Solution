class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);

        // current number, index
        vector<pair<char,int>> vp(s.length(), make_pair('0', -1));

        for(int i = s.length() - 1; i >= 0; i--){
            if(i == s.length() - 1){
                vp[i] = make_pair(s[s.length() - 1], i);
            }else{
                // compare the current number with current next number
                char currentNumber = s[i];
                char currentNextNumber = vp[i + 1].first;

                if(currentNumber < currentNextNumber){
                    // update the current max number to become current next number
                    int nextIndex = vp[i + 1].second;
                    vp[i] = make_pair(currentNextNumber, nextIndex);
                }else{
                    // keep it as it is
                    vp[i] = make_pair(s[i], i);
                }
            }
        }

        bool swapped = false;
        char swappedNumber = ' ';
        int swappedIndex = -1;
        for(int i = 0; i < s.length(); i++){
            if(vp[i].second != i && swapped == false){
                // swap
                swappedNumber = vp[i].first;
                swappedIndex = vp[i].second;
                swapped = true;
                swap(s[i], s[vp[i].second]);
            }else if(swapped == true && s[i] == swappedNumber){
                // cout << s[swappedIndex] << " " << s[i] << " " << swappedIndex << " " << i << endl;
                swap(s[swappedIndex],s[i]);
                swappedIndex = i;
            }
        }

        return stoi(s);
    }
};