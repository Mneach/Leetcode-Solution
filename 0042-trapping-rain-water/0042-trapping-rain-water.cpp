class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() <= 2) return 0;
        
        stack<pair<int,int>> bucket;
        bucket.push(make_pair(height[0], 1));
        int answer = 0;
        int mostLeft = height[0];
        
        for(int right = 1; right < height.size(); right++){
            
            int current = height[right];
            
            if(bucket.top().first <= current){
                
                if(mostLeft <= current){
                    current = mostLeft;
                }
                
                int totalReplacement = 0;
                while(bucket.empty() == false){
                    pair<int,int> currentTop = bucket.top();
                    
                    if(currentTop.first > current) break;
                    
                    if(bucket.size() > 1){
                        totalReplacement += currentTop.second;
                        answer += (current - currentTop.first) * currentTop.second;
                    }
                    
                    bucket.pop();
                }
                
                if(bucket.empty()){
                    
                    mostLeft = height[right];
                    bucket.push(make_pair(height[right], 1));
                }else{
                    bucket.push(make_pair(height[right], totalReplacement + 1));    
                }
                    
            }else{
                bucket.push(make_pair(current, 1));
            }
        }
        
        return answer;
    }
};