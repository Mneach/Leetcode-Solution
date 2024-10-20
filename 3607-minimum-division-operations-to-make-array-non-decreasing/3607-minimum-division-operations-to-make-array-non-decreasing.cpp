class Solution {
public:

    int getNumber(int num){
        
        int answer = INT_MAX;
        for(int i = 1; i * i <= num; i++){
            // larget number that we want to pick must be < num
            if(num % i == 0){
                int left = i;
                int right = num / i;

                if(right == num) continue;
                answer = min(answer, left);
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }

    int minOperations(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        
        int answer = 0;
        for(int i = nums.size() - 1; i > 0; i--){
            int current = nums[i];
            int currentPrev = nums[i - 1];

            if(currentPrev > current){
                int lowestNumber = getNumber(currentPrev);

                if(lowestNumber > current){
                    return -1;
                }else if(lowestNumber == -1){
                    return -1;
                }
                
                nums[i - 1] = lowestNumber;
                answer++;
            }

        }

        return answer;
    }
};

/*

how to solve : 
1. just need to check if nums[i] < nums[i + 1]
    need to find the largest number that can divide nums[i], so nums[i] become less than nums[i + 1]
2. otherwise, just increase the index

*/