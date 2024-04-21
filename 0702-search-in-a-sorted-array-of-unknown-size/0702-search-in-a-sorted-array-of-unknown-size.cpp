/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = 10000;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            if(reader.get(mid) > target){
                right = mid - 1;
            }else if(reader.get(mid) < target){
                left = mid + 1;
            }else if(reader.get(mid) == target){
                return mid;
            }
        }
        
        return -1;
    }
};