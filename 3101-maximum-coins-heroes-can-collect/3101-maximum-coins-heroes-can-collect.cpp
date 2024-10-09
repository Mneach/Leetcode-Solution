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

Solve using sort based on monster health + binary search

1. create pair that consist of monster health + coin
2. put those data into the bucket
3. calculate the coin
   3.1 save a curernt total coin variable
   3.2 increase current total coin by current coin
   3.3 change current coin with new current total coin
4. loop for every hero in heroes
   4.1 do binary search to find the coin that we can get based on the hero
5. return answer

Time Complexity = O(N Log N)
N log n -> to sort the data (we are using map datastructure)
N log n -> binary search to find the answer

Memory Complexity = O(M)
M -> total monster and coin
*/