class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> arr(26, make_pair(-1, -1));
        int answer = 0;


        for (int i = 0; i < s.length(); i++) {

            int index = s[i] - 'a';

            if (arr[index].first == -1) {
                arr[index].first = i;
            } else {
                arr[index].second = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            
            int start = arr[i].first;
            int end = arr[i].second;

            if (start == -1 || end == -1) continue;

            // cout << i << " " << start << " " << end << endl;

            set<char> st;
            for (int index = start + 1; index < end; index++) {
                st.insert(s[index]);
            }

            answer += st.size();
        }

        return answer;
    }
};