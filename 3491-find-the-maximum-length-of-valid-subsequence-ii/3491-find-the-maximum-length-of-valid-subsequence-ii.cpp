class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> bucket(k + 1);
        int answer = 0;
        
        for(int i = 0; i < nums.size(); i++){
            bucket[nums[i] % k].push_back(i);
        }

        for(int i = 0; i < k; i++){
            
            for(int j = 0; j < k; j++){
                int count = 1;
                int tempAnswer = 0;
                
                if(i == j){
                    tempAnswer = bucket[i].size() - 1;
                }else{
                    int index1 = 0;
                    int index2 = 0;
                    
                    while(index2 < bucket[j].size() && index1 < bucket[i].size() && bucket[j][index2] < bucket[i][index1]){
                        index2++;   
                    }
                    
                    while(index1 < bucket[i].size() && index2 < bucket[j].size()){
                        if(count % 2 == 1){
                            // get from the bucket one
                            index1++;
                            while(index1 < bucket[i].size() && bucket[i][index1] < bucket[j][index2]){
                                index1++;   
                            }
                        }else{
                            // get from the bucket two
                            index2++;
                            while(index2 < bucket[j].size() && bucket[j][index2] < bucket[i][index1]){
                                index2++;   
                            }
                        }
                        
                        tempAnswer++;
                        count++;
                    }
                }
                
                // cout << i << " " << j << " " << tempAnswer + 1 << endl;
                
                answer = max(tempAnswer + 1, answer);
            }
        }
        
        return answer;
    }
};