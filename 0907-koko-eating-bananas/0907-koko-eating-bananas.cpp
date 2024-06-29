class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int answer = INT_MAX;
	    int left = 1;
	    int right = *max_element(piles.begin(), piles.end());

        while(left <= right){
            int k = left + (right - left) / 2;
            
            long long int totalHour = 0;
            
            // loop from piles 0 until piles.size()
            for(int i = 0; i < piles.size(); i++){
                // we need to check the total hours to eats all bananas at piltes[i] with K = mid
                // formula to get a hour to eats all bananas at piles [i]
                // formula = (piles[i] / k) + 1 -> if piles[i] % k is not equal to zero
                // formula = (piles[i] / k) -> if piles[i] % k is equal to zero

                if(piles[i] % k == 0){
                    totalHour += (piles[i] / k);
                }else{
                    totalHour += (piles[i] / k) + 1;
                }
            }
                    
            if(totalHour <= h){
                // answer is valid
                right = k - 1;
                answer = min(answer, k);
            }else{
                // answer is not valid
                left = k + 1;
            }
                    
        }

        return answer;

    }
};