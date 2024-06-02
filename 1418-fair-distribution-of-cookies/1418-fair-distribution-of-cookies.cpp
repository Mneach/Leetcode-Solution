class Solution {
public:

    void dfs(vector<int>& cookies, vector<int> &distribution, int current, int k, int &answer){
        if(current == cookies.size()){
            
            int temp = INT_MIN;

            for(auto data : distribution){
                temp = max(temp, data);
            }

            answer = min(answer, temp);
            return;
        }

        // distribute the cookie to all child
        for(int i = 0; i < k; i++){
            distribution[i] += cookies[current];
            dfs(cookies, distribution, current + 1, k, answer);
            distribution[i] -= cookies[current];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribution(k , 0);
        int answer = INT_MAX;

        dfs(cookies, distribution, 0, k, answer);

        return answer;
    }
};