class Solution {
public:
    bool checkValidCuts(int n, std::vector<std::vector<int>>& rectangles) {
        return isValidCut(rectangles, 0) || isValidCut(rectangles, 1);
    }

private:
    bool isValidCut(std::vector<std::vector<int>>& rectangles, int dimension) {
        int gapCount = 0;
        
        // Sort rectangles by starting coordinate in the given dimension
        std::sort(rectangles.begin(), rectangles.end(), 
                  [dimension](const std::vector<int>& a, const std::vector<int>& b) {
                      return a[dimension] < b[dimension];
                  });
        
        int maxEnd = rectangles[0][dimension + 2];
        
        for (size_t i = 1; i < rectangles.size(); ++i) {
            const auto& rect = rectangles[i];
            
            if (maxEnd <= rect[dimension]) {
                ++gapCount;
            }
            
            maxEnd = std::max(maxEnd, rect[dimension + 2]);
        }
        
        return gapCount >= 2;
    }
};