class Solution {
public:

    long long int maxLL(long long a, long long b){
        if(a > b) return a;
        else return b;
    }

    double averageWaitingTime(vector<vector<int>>& customers) {
        long long int idle1,idle2;
        idle1 = idle2 = 0;

        for(int i = 0; i < customers.size(); i++){
            int arrivalTime = customers[i][0];
            int time = customers[i][1];

            idle1 = maxLL(arrivalTime, idle1) + time;

            idle2 += idle1 - arrivalTime;
        }

        double answer = (double) idle2 / customers.size();

        return answer;
    }
};