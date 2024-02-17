using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int lo = 0;
        int hi = heights.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (isReachable(mid, heights, bricks, ladders)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return hi; 
    }
    
private:
    bool isReachable(int buildingIndex, vector<int>& heights, int bricks, int ladders) {
        vector<int> climbs;
        for (int i = 0; i < buildingIndex; i++) {
            int h1 = heights[i];
            int h2 = heights[i + 1];
            if (h2 <= h1) {
                continue;
            }
            climbs.push_back(h2 - h1);
        }
        sort(climbs.begin(), climbs.end());
        
        for (int climb : climbs) {
            if (climb <= bricks) {
                bricks -= climb;
            } else if (ladders >= 1) {
                ladders -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};
