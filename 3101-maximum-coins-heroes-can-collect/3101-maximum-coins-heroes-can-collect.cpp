class Solution {
public: 
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        vector<long long> answer;
        map<long long, long long> bucket;
        int maximumHero = *max_element(heroes.begin(), heroes.end());

        for(int i = 0; i < monsters.size(); i++){
            bucket[monsters[i]] += coins[i];
        }

        long long currentCoin = 0;
        for(auto &coin : bucket){
            currentCoin += coin.second;
            coin.second = currentCoin;
        }

        for(auto hero : heroes){
            auto iterator = bucket.lower_bound(hero);
            
            if(iterator == bucket.end()){
                answer.push_back(currentCoin);
            }else{
                long long first = (*iterator).first;
                long long second = (*iterator).second;

                if(iterator == bucket.begin()){
                    if(first == hero){
                        answer.push_back(second);
                    }else{
                        answer.push_back(0);
                    }
                }else if(first == hero){
                    answer.push_back(second);
                }else{
                    iterator--;
                    answer.push_back((*iterator).second);
                }
            }
        }

        return answer;
    }
};

/*

Solve using sort + prefix sum

1. we will try to pair monster with coin
2. sort based on the monster health
3. looping from hero 0 until hero n
4. if hero health >= monster health
   4.1 add the current coin to the variable
5. if hero health < monster health
   5.1 push the current coin value to the array of answer 

Time Complexity = (N * log n) + n
N log n -> from sort algorithm
N -> from loop all of the heroes and return the coin based on selecter hero

Memory Complexity = (N + M)
N -> Total Pair Monster and Hero
M -> Total Heroes

*/