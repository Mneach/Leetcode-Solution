class Solution {
public:
    string triangleType(vector<int>& nums) {
        int x = nums[0];
        int y = nums[1];
        int z = nums[2];

        int maximum = max({x, y, z});

        if (x + y + z - maximum <= maximum) {
            return "none";
        }

        if (x == y && x == z && y == z) {
            return "equilateral";
        } else if (x == y || y == z || x == z) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};