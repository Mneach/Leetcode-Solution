class Solution {
public:
    int numberCount(int a, int b) {
        vector<int> bucket(1001, 0);

        for(int i = 0; i <= 1000; i++){
            if(i > 0 && i <= 10){
                bucket[i] = bucket[i - 1] + 1;
            }else if(i > 10 && i <= 99){
                if(i % 11 == 0){
                    bucket[i] = bucket[i - 1];
                }else{
                    bucket[i] = bucket[i - 1] + 1;
                }
            }else if(i >= 100 && i <= 1000){
                string temp = to_string(i);

                if(temp[0] == temp[temp.size() - 1] || temp[0] == temp[1] || temp[temp.size() - 2] == temp[temp.size() - 1]){
                    bucket[i] = bucket[i - 1];
                }else{
                    bucket[i] = bucket[i - 1] + 1;
                }
            }
        }


        return (bucket[b] - bucket[a - 1]);
    }
};