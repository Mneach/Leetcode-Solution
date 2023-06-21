class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> pref_product(nums.size());
        vector<int> suf_product(nums.size());
        
        pref_product[0] = 1;
        suf_product[nums.size() - 1] = 1;
        
        for(int i = 1; i < nums.size(); i++){
            pref_product[i] = nums[i - 1] * pref_product[i - 1];
        }
        
        for(int j = nums.size() - 2; j >= 0; j--){
            suf_product[j] = nums[j + 1] * suf_product[j + 1];
        }
        
        vector<int> answer(nums.size());
        
        for(int i = 0; i < pref_product.size(); i++){
            answer[i] = pref_product[i] * suf_product[i];
        }
        
        return answer;
    }
};