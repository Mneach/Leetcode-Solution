class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        auto canAssign = [&](int count) -> bool {
            int pillsLeft = pills;
            deque<int> availableWorkers;
            int workerIndex = m - 1;

            for (int i = count - 1; i >= 0; --i) {
                // Add workers that can potentially do the task with or without a pill
                while (workerIndex >= m - count && workers[workerIndex] + strength >= tasks[i]) {
                    availableWorkers.push_front(workers[workerIndex--]);
                }

                if (availableWorkers.empty()) {
                    return false;
                }

                // Assign strongest available worker without pill
                if (availableWorkers.back() >= tasks[i]) {
                    availableWorkers.pop_back();
                } else {
                    // Use a pill with the weakest worker if possible
                    if (pillsLeft == 0) return false;
                    --pillsLeft;
                    availableWorkers.pop_front();
                }
            }
            return true;
        };

        // Binary search for the maximum number of tasks that can be assigned
        int low = 1, high = min(n, m), maxTasks = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canAssign(mid)) {
                maxTasks = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return maxTasks;
    }
};
