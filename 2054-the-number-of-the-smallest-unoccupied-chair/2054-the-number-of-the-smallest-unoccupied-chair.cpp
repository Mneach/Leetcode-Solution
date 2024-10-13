class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        // sort(times.begin(), times.end());

        // for(auto data : times){
        //     cout << data[0] << " " << data[1] << endl;
        // }

        priority_queue<int, vector<int>, greater<int>> bucketStack;
        unordered_map<int,int> ump;
        unordered_map<int,vector<int>> bucketTime;

        for(auto data : times){
            int start = data[0];
            int end = data[1];

            ump[start] = end;
        }

        for(int i = 1e5 + 1; i >= 0; i--){
            bucketStack.push(i);
        }

        int currentTime = 1;
        int totalTime = times[targetFriend][0];
        
        while(currentTime <= totalTime){
            if(bucketTime.count(currentTime) > 0){
                // there is a people that want to leave

                // chair will be available again
                for(int i = 0; i < bucketTime[currentTime].size(); i++){
                    bucketStack.push(bucketTime[currentTime][i]);
                }
                // reset the bucketTime[currentTime]
                bucketTime.erase(currentTime);
            }

            if(ump[currentTime] > 0){
                // there is a people that want to sit
                int start = currentTime;
                int end = ump[currentTime];

                if(currentTime == totalTime) return bucketStack.top();

                bucketTime[end].push_back(bucketStack.top());
                bucketStack.pop();
            }

            currentTime++;
        }

        return bucketStack.top();
    }
};

/*

Intuition
- Looping only until target friend start

*/