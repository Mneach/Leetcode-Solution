class Solution {
public:

    string dfs(int n, string current) {
        if (n <= 1) {
            return current;
        }

        string result = "";

        int count = 1;
        for (int i = 0; i < current.length() - 1; i++) {
           if (current[i] == current[i + 1]) {
                count++;
           } else {
                char total = count + '0';
                result += total;
                result += current[i];
                count = 1;
           }
        }

        char total = count + '0';
        result += total;
        result += current[current.length() - 1];

        return dfs(n - 1, result);
    }

    string countAndSay(int n) {
       return dfs(n, "1"); 
    }
};