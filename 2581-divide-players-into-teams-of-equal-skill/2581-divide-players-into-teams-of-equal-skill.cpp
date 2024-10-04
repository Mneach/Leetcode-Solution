class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        if(skill.size() == 2){
            return 1LL * skill[0] * skill[1];
        }

        unordered_map<long long,long long> ump;
        long long total = 0;

        for(auto data : skill){
            ump[data]++;
            total += data;
        }

        cout << total << endl;

        total /= (skill.size() / 2);
        long long answer = 0;
        
        for(int i = 0; i < skill.size(); i++){
            int number = skill[i];
            if(ump[number] == 0) continue;

            if(ump[total - number] > 0){
                ump[number]--;
                ump[total - number]--;
                answer += (1LL * number * (total - number));
            }else{
                return -1;
            }
        }

        return answer;
    }
};