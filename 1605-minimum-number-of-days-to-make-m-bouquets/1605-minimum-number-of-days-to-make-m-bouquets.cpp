class Solution {
public:

    int helper(int minimumDay, vector<int>& bloomDay, int k){
        
        int count = 0;
        int res = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= minimumDay){
                count++;
            }else{
                count = 0;
            }

            if(count == k){
                res++;
                count = 0;
            }
        }

        return res;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int answer = INT_MAX;

        if((long long int) m * k > bloomDay.size()) return -1;

        int left = 1;
        int right = *max_element(bloomDay.begin(), bloomDay.end());

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(helper(mid, bloomDay, k) >= m){
                answer = min(answer, mid);
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return answer;
    }
};