/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int size = reader.length();
        int left = 0;
        int right = size - 1;
        
        while(left < right){
            int mid = left + (right - left) / 2;
            
            if((right - left) % 2 == 0){
                int comp = reader.compareSub(left,mid-1,mid+1,right);

                if(comp == 0){
                    return mid;
                }else if(comp == 1) {
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if(reader.compareSub(left,mid,mid+1,right) == 1) {
                    right = mid;
                }else{
                    left = mid + 1;
                }
            }
        }
        return left;
    }
};