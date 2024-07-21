class NumArray {
public:

    vector<int> arr;
    int n;

    void constructTree(vector<int> &arr, vector<int> &nums, int low, int high, int pos){
        if(low == high){
            cout << pos << " " << low << endl;
            arr[pos] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;
        constructTree(arr, nums , low, mid, (pos * 2) + 1);
        constructTree(arr, nums, mid + 1, high, (pos * 2) + 2);

        arr[pos] = arr[(pos * 2) + 1] + arr[(pos * 2) + 2];
    }

    void updateTree(vector<int> &arr, int low, int high, int index, int pos, int val){
        // no overlap
        if(index < low || index > high) return;

        // total overlap
        if(low == high && low == index){
            arr[pos] = val;
            return;
        }

        int mid = low + (high - low) / 2;
        int leftPos = pos * 2 + 1;
        int rightPos = pos * 2 + 2;
        updateTree(arr, low, mid, index, leftPos, val);
        updateTree(arr, mid + 1, high, index, rightPos, val);

        arr[pos] = arr[leftPos] + arr[rightPos];
    }

    int result(vector<int>& arr, int low, int high, int left, int right, int pos){
        // total overlap
        if(left <= low && right >= high){
            return arr[pos];
        }

        // no overlap
        if(left > high || right < low){
            return 0;
        }

        
        int mid = low + (high - low) / 2;
        int leftPos = pos * 2 + 1;
        int rightPos = pos * 2 + 2;
        
        int leftResult = result(arr, low, mid, left, right, leftPos);
        int rightResult = result(arr, mid + 1, high, left, right, rightPos);

        return leftResult + rightResult;
    }

    void print(vector<int> nums){
        for(auto data : nums) cout << data << " " ;
    }

    NumArray(vector<int>& nums) {
        arr.resize(nums.size() * 4);
        n = nums.size();

        constructTree(arr, nums, 0, nums.size() - 1, 0);
        print(arr);
    }
    
    void update(int index, int val) {
        updateTree(arr, 0, n - 1, index, 0, val);
    }
    
    int sumRange(int left, int right) {
        return result(arr, 0, n - 1, left, right, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */