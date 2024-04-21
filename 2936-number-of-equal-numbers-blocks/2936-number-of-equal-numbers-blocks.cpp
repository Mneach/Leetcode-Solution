/**
 * Definition for BigArray.
 * class BigArray {
 * public:
 *     BigArray(vector<int> elements);
 *     int at(long long index);
 *     long long size();
 * };
 */
class Solution {
public:
    int countBlocks(BigArray* nums) {
        int answer = 0;
        
        long long int index = 0;
        long long int size = nums->size();
        while(index < size){
            long long int findNumber = nums->at(index);
            long long int left = index;
            long long int right = size - 1;
            
            while(left <= right){
                long long int mid = left + (right - left) / 2;
                
                if(nums->at(mid) != findNumber){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            
            index = max(left, right);
            answer++;
        }
        
        return answer;
    }
};