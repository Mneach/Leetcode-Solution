class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int end = people.size() - 1;
        int start = 0;
        
        int answer = 0;
        while(start <= end){
            
            if(people[start] + people[end] > limit || start == end){
                answer++;
                end--;
            }else{
                answer++;
                start++;
                end--;
            }
        }
        
        return answer;
    }
};