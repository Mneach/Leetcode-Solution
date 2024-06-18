class Solution {
public:

    int binarySearch(vector<pair<int,int>> &vp, int workerVal){

        int left = 0;
        int right = vp.size() - 1;
        
        int res = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(workerVal < vp[mid].first){
                right = mid - 1;
            }else{
                res = max(res, vp[mid].second);
                left = mid + 1;
            }
        }

        cout << res << endl;

        return res;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vp;

        for(int i = 0; i < profit.size(); i++){
            vp.push_back({difficulty[i], profit[i]});
        }

        sort(vp.begin(), vp.end());

        int currentMax = 0;

        for(int i = 0; i < vp.size(); i++){
            if(i == 0) {
                currentMax = vp[i].second;
            }else {
                currentMax = max(currentMax, vp[i].second);
                vp[i].second = currentMax;
            }
        }

        int answer = 0;

        for(int i = 0; i < worker.size(); i++){
            answer += binarySearch(vp, worker[i]);
        }

        return answer;
    }
};