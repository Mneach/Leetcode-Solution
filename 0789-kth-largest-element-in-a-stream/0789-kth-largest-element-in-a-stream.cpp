class KthLargest {
public:

    vector<int> arr;
    int number = 0;

    KthLargest(int k, vector<int>& nums) {
        number = k;
        for(auto data : nums){
            if(arr.size() == 0){
                arr.push_back(data);
            }else{
                int index = lower_bound(arr.begin(), arr.end(), data) - arr.begin();
                arr.insert(arr.begin() + index, data);
            }
        }
    }
    
    int add(int val) {
        
        int index = lower_bound(arr.begin(), arr.end(), val) - arr.begin();
        arr.insert(arr.begin() + index, val);

        return arr[arr.size() - number];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */