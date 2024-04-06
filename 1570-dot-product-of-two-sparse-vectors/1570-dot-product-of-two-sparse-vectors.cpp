class SparseVector {
public:
    
    unordered_map<int, int> ump;
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                ump[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
        int answer = 0;
        for(auto data : vec.ump){
            if(ump.count(data.first) > 0){
                answer += (ump[data.first] * data.second);
            }
        }
        
        return answer;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);