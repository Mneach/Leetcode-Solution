class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = INT_MAX;

        while(left < right){
            int mid = left + (right - left) / 2;
            int total = 0;
            
            for(int q : quantities){
                total += (q + mid - 1) / mid;
            }

            if(total > n) left = mid + 1;
            else right = mid;
        }

        return left;
    }
};