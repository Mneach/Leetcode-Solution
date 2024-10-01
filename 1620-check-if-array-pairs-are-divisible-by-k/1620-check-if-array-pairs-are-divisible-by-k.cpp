class Solution {
private:

    long long min(long long a, long long b){
        if(a > b) return b;
        else return a;
    }

    long long max(long long a, long long b){
        if(a > b) return a;
        else return b;
    }

public:
    bool canArrange(vector<int>& arr, long long k) {
        
        unordered_map<long long,long long> ump;

        for(auto data : arr){
            long long result = ((data % k) + k) % k;
            ump[result]++;
        }

        int total = 0;

        for(int i = 0; i < k; i++){
            
            if(i == 0){
                total += ump[0] / 2;
            }else if(i == k - i){
                total += ump[i] / 2;
            }else if(ump[i] == ump[k - i] && ump[i] > 0 && ump[k - i] > 0){
                total += ump[i];
                ump[i] = 0;
                ump[k - i] = 0;
            }
        }

        cout << total << endl;

        if(total >= arr.size() / 2){
            return true;
        }else{
            return false;
        }
    }
};