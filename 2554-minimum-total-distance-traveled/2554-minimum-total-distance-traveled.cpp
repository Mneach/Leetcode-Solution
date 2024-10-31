class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());

        vector<int> expandedFactoryPositions;
        for (const auto& factory : factories) {
            int position = factory[0], capacity = factory[1];
            expandedFactoryPositions.insert(expandedFactoryPositions.end(), capacity, position);
        }

        int robotCount = robots.size();
        int factoryCount = expandedFactoryPositions.size();
        vector<vector<long long>> memo(robotCount, vector<long long>(factoryCount, -1));

        return calculateMinimumDistance(0, 0, robots, expandedFactoryPositions, memo);
    }

private:
    long long calculateMinimumDistance(int robotIdx, int factoryIdx, vector<int>& robots,
                                       vector<int>& factoryPositions, vector<vector<long long>>& memo) {
        // Base cases
        if (robotIdx == robots.size()) return 0;  // All robots assigned
        if (factoryIdx == factoryPositions.size()) return 1e12;  // No factories left

        // Memoization check
        if (memo[robotIdx][factoryIdx] != -1) return memo[robotIdx][factoryIdx];

        // Option 1: Assign current robot to current factory
        long long assignDistance = abs(robots[robotIdx] - factoryPositions[factoryIdx]) +
                                   calculateMinimumDistance(robotIdx + 1, factoryIdx + 1, robots, factoryPositions, memo);

        // Option 2: Skip current factory for the current robot
        long long skipDistance = calculateMinimumDistance(robotIdx, factoryIdx + 1, robots, factoryPositions, memo);

        // Store the minimum of assigning or skipping
        memo[robotIdx][factoryIdx] = min(assignDistance, skipDistance);
        return memo[robotIdx][factoryIdx];
    }
};
