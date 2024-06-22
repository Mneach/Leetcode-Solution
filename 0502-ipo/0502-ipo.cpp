class Data{
public:
    long long int profit;
    long long int capital;

    Data(long long int profit, long long int capital){
        this->profit = profit;
        this->capital = capital;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, long long int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<long long int> pq;
        vector<Data> arr;
        long long int answer = w;

        for(int i = 0; i < profits.size(); i++){
            arr.push_back(Data(profits[i], capital[i]));
        }

        sort(arr.begin(), arr.end(), [](Data &first, Data& second){
            return first.capital < second.capital;
        });

        for(int i = 0; i < arr.size(); i++){
            if(w >= arr[i].capital){
                pq.push(arr[i].profit);
            }else if(w < arr[i].capital && pq.size() > 0){
                answer += pq.top();
                w += pq.top();
                k--;
                pq.pop();

                while(w < arr[i].capital && pq.size() > 0 && k > 0){
                    w += pq.top();
                    answer += pq.top();
                    k--;
                    pq.pop();
                }

                if(k == 0) break;

                if(w >= arr[i].capital){
                    long long int test = arr[i].profit;
                    pq.push(arr[i].profit);
                }
            }
        }

        while(k > 0 && pq.size() > 0){
            answer += pq.top();
            pq.pop();
            k--;
        }

        return answer;
    }
};