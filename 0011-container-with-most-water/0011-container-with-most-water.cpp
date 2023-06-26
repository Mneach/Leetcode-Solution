class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int size = height.size() - 1;
        int left = 0;
        int answer = 0;
        int right = size;
        int currentSize = size;
        
        while(left < right){
            answer = max(answer, min(height[left], height[right]) * currentSize);
            
            // printf("%d %d %d %d\n", height[left], height[right], currentSize, answer);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }          
            currentSize--;
        }
        
        return answer;
    }
};