class Solution {
public:
    bool canChange(string start, string target) {
        
        int startIndex = 0;
        int targetIndex = 0;

        while (startIndex < start.size() || targetIndex < target.size()) {

            while (startIndex < start.size() && start[startIndex] == '_') {
                startIndex++;
            }

            while (targetIndex < target.size() && target[targetIndex] == '_') {
                targetIndex++;
            }

            if (startIndex == start.size() || targetIndex == target.size()) {
                return startIndex == start.size() && targetIndex == target.size();
            }

            if (start[startIndex] != target[targetIndex]) return false;
            else if (start[startIndex] == 'L' && startIndex < targetIndex) return false;
            else if (start[startIndex] == 'R' && startIndex > targetIndex) return false;

            startIndex++;
            targetIndex++;
        }

        return true;
    }
};