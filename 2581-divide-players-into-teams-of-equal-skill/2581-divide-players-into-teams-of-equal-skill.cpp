class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        long long answer = 0;

        int left = 0;
        int right = skill.size() - 1;
        long long target = skill[left] + skill[right];

        while(left < right){
            long long temp = skill[left] + skill[right];
            cout << target << " " << temp << endl;
            if(temp != target) return -1;
            
            answer += (1LL * skill[left] * skill[right]);
            left++;
            right--;
        }

        return answer;
    }
};