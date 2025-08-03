class Solution {
public:
    int distanceBetweenBusStops(std::vector<int>& distances, int start,
                                int destination) {
        // Ensure start is the smaller index to simplify the loop logic
        if (start > destination) {
            std::swap(start, destination);
        }

        int clockwise_distance = 0;
        int total_distance = 0;

        for (int i = 0; i < distances.size(); ++i) {
            if (i >= start && i < destination) {
                clockwise_distance += distances[i];
            }
            total_distance += distances[i];
        }

        // The counter-clockwise distance is total minus clockwise
        int counter_clockwise_distance = total_distance - clockwise_distance;

        return std::min(clockwise_distance, counter_clockwise_distance);
    }
};