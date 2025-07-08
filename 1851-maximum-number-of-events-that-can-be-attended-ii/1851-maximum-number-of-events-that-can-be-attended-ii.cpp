/*

How to solve : 
1. there are only 2 ways, take the current event or skip the current event
2. if we take the current event, the next event that must be have start time > current event end time (to find this we can use binary search) and decrease the value k
3. if we skip the current event, we just need to move into the next index and keep the value k

Time Complexity : O(N) * K
Since the maximum step that we can take is K and we need to loop for every event in the array of events

Memory Copmlexity : O(N) * K
Because we need to cache for every combination index and remaining K value

*/

class Solution {
public:
    int recursive(vector<vector<int>>& events, vector<vector<int>>& cache, int index, int k) {
        if (k <= 0) return 0;
        if (index >= events.size()) return 0; 

        if (cache[index][k] != -1) {
            return cache[index][k];
        }

        int start = events[index][0];
        int end = events[index][1];
        int value = events[index][2]; 

        int nextIndex = upper_bound(events.begin() + index, events.end(), end, [](int end, vector<int>& event){
            return event[0] > end;
        }) - events.begin();

        int take = recursive(events, cache, nextIndex, k - 1);
        int skip = recursive(events, cache, index + 1, k);

        int result = max(take + value, skip);
        cache[index][k] = result;
        return result;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> cache(events.size() + 1, vector<int>(k + 1, -1));

        return recursive(events, cache, 0, k);
    }
};