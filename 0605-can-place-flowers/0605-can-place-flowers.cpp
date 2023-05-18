class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int length = flowerbed.size();
   
        if(length == 1) {
            if(n == 1) return flowerbed[0] == 0;
            else return true;
        }
        
        for(int i = 0; i < length; i++){
            
            if(flowerbed[i] == 1) continue;
            
            if(i == 0){
                if(flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }else if(i == length - 1){
                if(flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }else{
                if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }

            }
        }
        
        return n <= 0;
    }
};