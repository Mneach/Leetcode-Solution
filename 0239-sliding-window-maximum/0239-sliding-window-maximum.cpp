class Solution {
public:
    
    void printPq(priority_queue<pair<int,int>> pq){
        
        while(!pq.empty()){
            cout << pq.top().first << " " << pq.top().second << endl;
            pq.pop();
        }
        cout << "==========" << endl;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> answer;
        
       priority_queue<pair<int, int> > pq;
 
       for(int i = 1; i <= nums.size(); i++){
            if(i < k){
                pq.push(make_pair(nums[i - 1] , i));
            }else{
                pq.push(make_pair(nums[i - 1], i));
                
              
                while(pq.top().second <= i - k){
                    pq.pop();
                }
                    
                answer.push_back(pq.top().first);
            }
       }

        return answer;
    }
};