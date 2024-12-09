class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        // first = start
        // second = end
        vector<pair<int,int>> arr;
        vector<bool> answer;
        
        int start = -1;
        int end = -1;
        
        // 1. looping for every number
        // 2. check if is not special array
        // 3. take a range of that
        // 4. save on the array

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] % 2 == 0 && nums[i + 1] % 2 == 0){
                if(start == -1) {
                    start = i;
                    end = i + 1;
                }else{
                    end = i + 1;
                }
            }else if(nums[i] % 2 != 0 && nums[i + 1] % 2 != 0){
                if(start == -1) {
                    start = i;
                    end = i + 1;
                }else{
                    end = i + 1;
                }
            }else{
                if(start != -1 && end != -1){
                    arr.push_back({start, end});
                    start = -1;
                    end = -1;
                }
            }
        }
        
        if(start != -1 && end != -1){
            arr.push_back({start, end});
        }
        
        // for every query
        // 1. using binary search to check the start and end index
        
        for(int i = 0; i < queries.size(); i++){
            start = queries[i][0];
            end = queries[i][1];
            
            if(start == end){
                answer.push_back(true);
                continue;
            }
            
            // try using iterative O(n)
            bool temp = true;
            for(auto data : arr){
                int startRange = data.first;
                int endRange = data.second;
                

                if(start >= startRange && end <= endRange){
                    // inside the range
                    temp = false;
                    break;
                }else if(start >= startRange && start < endRange){
                    // start index is inside the range
                    temp = false;
                    break;
                }else if(end > startRange && end <= endRange){
                    // end index is inside the range
                    temp = false;
                    break;
                }else if(start <= startRange && end >= endRange){
                    temp = false;
                    break;
                }
            }
            
            answer.push_back(temp);
        }
        
        return answer;
    }
};