class FindSumPairs {
private:
    unordered_map<int,int> bucket1;
    unordered_map<int,int> bucket2;
    vector<int> nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto num : nums1) bucket1[num]++;
        for (auto num : nums2) {
            bucket2[num]++;
            this -> nums2.push_back(num);
        }
    }
    
    void add(int index, int val) {
        int currentValue = nums2[index];
        bucket2[currentValue]--;
        
        nums2[index] += val;
        bucket2[nums2[index]]++;
    }
    
    int count(int tot) {
        int answer = 0;
        for (auto data : bucket1) {
            int key = data.first;
            int value = data.second;

            if (key > tot) continue;
            int remaining = tot - key;

            int totalFromBucket2 = bucket2[remaining];

            answer += value * totalFromBucket2;
        }

        return answer;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */