class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int answer = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int firstResult = abs(arr[i] - arr[j]);
                if (firstResult <= a) {
                    for (int k = j + 1; k < arr.size(); k++) {
                        int secondResult = abs(arr[j] - arr[k]);
                        int thirdResult = abs(arr[i] - arr[k]);

                        if (secondResult <= b && thirdResult <= c) {
                            answer++;
                        }
                    }
                }
            }
        }

        return answer;
    }
};