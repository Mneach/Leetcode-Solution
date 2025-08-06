class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for (string& email : emails) {
            string cleanEmail;
            for (char x : email) {
                if (x == '+' || x == '@') {
                    break;
                }
                if (x == '.') {
                    continue;
                }
                cleanEmail += x;
            }
            cleanEmail += email.substr(email.find('@'));
            st.insert(cleanEmail);
        }
  
        return st.size();
    }
};