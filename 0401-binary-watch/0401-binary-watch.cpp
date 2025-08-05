class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> times;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (bitset<10>(h * 64 + m).count() == turnedOn) {
                    stringstream ss;
                    ss << h << ":" << setw(2) << setfill('0') << m;
                    times.push_back(ss.str());
                }
            }
        }
        return times;
    }
};