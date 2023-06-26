class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> result;
        
        for(int i = 0; i < asteroids.size(); i++){
            int x = asteroids[i]; // current element of asteroids
            
            if(result.empty() == true) {
                result.push(x);
            }else{
                int last = result.top(); // most top element in stack
                
                if(last > 0 && x > 0) result.push(x);
                else if(last < 0 && x < 0) result.push(x);
                else if(last + x == 0 && last > 0) result.pop();
                else if(last < 0 && x > 0) result.push(x);
                else if(last > 0 && x < 0){
                    while(result.empty() == false && last > 0 && last + x < 0){
                        result.pop();
                        if(result.empty() == false) last = result.top();
                    }
                    
                    if(last + x == 0) result.pop();
                    else if(result.empty() == true) result.push(x);
                    else if(last < 0) result.push(x); 
                }
            }
        }
        
        vector<int> answer;
        
        while(result.empty() == false){
            answer.push_back(result.top());
            result.pop();
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};