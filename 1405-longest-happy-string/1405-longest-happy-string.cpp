class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0) pq.push(make_pair(a, 'a'));
        if(b > 0) pq.push(make_pair(b, 'b'));
        if(c > 0) pq.push(make_pair(c, 'c'));
        
        string answer = "";
        while(pq.empty() == false){
            pair<int,char> top = pq.top();
            
            pq.pop();
            
            if(pq.empty()){
                if(top.first > 2){
                    answer += top.second;
                    answer += top.second;
                }else {
                    answer += top.second;
                }
                
                break;
            }
            
            if(pq.top().first + 2 <= top.first){
                answer += top.second;
                answer += top.second;
                top.first -= 2;
                
                pair<int,char> nextTop = pq.top();
                pq.pop();
                answer += nextTop.second;
                nextTop.first -= 1;
                                
                if(top.first > 0){  
                    pq.push(top);
                }
                
                if(nextTop.first > 0){
                    pq.push(nextTop);                    
                }
            }else{
                answer += top.second;
                top.first -= 1;
                if(top.first > 0){
                    pq.push(top);    
                }
            }
            // cout << top.first << " " << top.second << " " << answer << endl;
        }
        
        return answer;
    }
};