class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx == fx && sy == fy){
            if(t == 1) return false;
            else return true;
        }
       
        long long minimumDiagonal = min(abs(sx - fx), abs(sy - fy));
        
        if(fx < sx && fy < sy){
            fx += minimumDiagonal;
            fy += minimumDiagonal;
        }else if(sx < fx && sy < fy){
            sx += minimumDiagonal;
            sy += minimumDiagonal;
        }else if(sx > fx && sy < fy){
            sx -= minimumDiagonal;
            sy += minimumDiagonal;
        }else if(sx < fx && sy > fy){
            fx -= minimumDiagonal;
            fy += minimumDiagonal;
        }
       
        long long time = minimumDiagonal + (abs(sx - fx)) + abs(sy - fy);
        
        if(time <= t) return true;
        else return false;
    }
};