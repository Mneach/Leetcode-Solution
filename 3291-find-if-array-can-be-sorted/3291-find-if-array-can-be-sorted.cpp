class Solution {
public:

    int countBits(int number){
        int result = 0;

        while(number > 0){
            if(number % 2 == 1){
                result++;
            }
            number /= 2;
        }

        return result;
    }

    bool canSortArray(vector<int>& nums) {
        
        unordered_map<int,int> ump;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 1; i <= 1000; i++){
            int result = countBits(i);

            ump[i] = result;
        }

        for(int i = 0; i < nums.size() - 1; i++){
            int current = nums[i];
            int next = nums[i + 1];

            if(current > next){
                if(ump[current] == ump[next]){
                    swap(nums[i], nums[i + 1]);
                }else{
                    return false;
                }
            }
        }

        vector<int> temp;

        for(int i = 0; i < nums.size() - 1; i++){
            int current = nums[i];
            int next = nums[i + 1];

            pq.push(current);

            if(ump[current] != ump[next]){
                while(pq.size() > 0){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }
        }

        pq.push(nums[nums.size() - 1]);

        while(pq.size() > 0){
            temp.push_back(pq.top());
            pq.pop();
        }

        // check if sorted 
        for(int i = 0; i < temp.size() - 1; i++){
            if(temp[i] > temp[i + 1]) return false;
        }

        return true;
    }
};