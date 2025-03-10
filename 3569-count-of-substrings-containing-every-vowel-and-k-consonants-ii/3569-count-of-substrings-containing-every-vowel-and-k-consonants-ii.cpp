long long maximum = 2e5;
vector<vector<int>> prefixSum(maximum + 2, vector<int>(6, 0));

class Solution {
    bool checkValidVowels(long long left, long long right){
        for(long long i = 0; i < 5; i++){
            if(prefixSum[right + 1][i] - prefixSum[left][i] == 0) return false;
        }

        return true;
    }

    long long countConsonant(long long left, long long right){
        return (right - left + 1) - (prefixSum[right + 1][5] - prefixSum[left][5]);
    }

    long long getLeftPointer(long long start, long long size, long long k){
        long long s = start;
        long long end = size - 1;
        long long result = size;

        while(s <= end){
            long long mid = s + (end - s) / 2;
            if(checkValidVowels(start, mid) && countConsonant(start, mid) >= k){
                result = mid;
                end = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return result;
    }

    long long getRightPointer(long long start, long long size, long long k){
        long long s = start;
        long long end = size - 1;
        long long result = start -1;

        while(s <= end){
            long long mid = s + (end - s) / 2;
            if(countConsonant(start, mid) <= k){
                result = mid;
                s = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        return result;
    }

public:
    long long countOfSubstrings(string word, long long k) {
        // compute prefix sum of vowels
        for(long long i = 0; i < 6; i++){
            prefixSum[0][i] = 0;
        }
        for(long long i = 0; i < word.length(); i++){
            char c = word[i];

            for(long long j = 0; j < 6; j++){
                prefixSum[i + 1][j] = prefixSum[i][j];
            }

            if(c == 'a'){
                prefixSum[i + 1][0]++;
                prefixSum[i + 1][5]++;
            }else if (c == 'i'){
                prefixSum[i + 1][1]++;
                prefixSum[i + 1][5]++;
            }else if (c == 'u'){
                prefixSum[i + 1][2]++;
                prefixSum[i + 1][5]++;
            }else if (c == 'e'){
                prefixSum[i + 1][3]++;
                prefixSum[i + 1][5]++;
            }else if (c == 'o'){
                prefixSum[i + 1][4]++;
                prefixSum[i + 1][5]++;
            }
        }

        long long answer = 0;
        // compute answer
        for(long long i = 0; i < word.size(); i++){
            long long leftPointer = getLeftPointer(i, word.size(), k);
            long long rightPointer = getRightPointer(i, word.size(), k);

            if(leftPointer <= rightPointer){
                answer += (rightPointer - leftPointer) + 1;
            }
        } 

        return answer;
    }
};