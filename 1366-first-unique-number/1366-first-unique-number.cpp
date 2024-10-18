class FirstUnique {
public:

    unordered_map<int,int> bucket;
    queue<int> st;
    FirstUnique(vector<int>& nums) {
        for(auto number : nums){
            st.push(number);
            bucket[number]++;
        }    
    }
    
    int showFirstUnique() {
        while(st.size() > 0 && bucket[st.front()] > 1){
            st.pop();
        }

        if(st.size() == 0) return -1;
        else return st.front();
    }
    
    void add(int value) {
        bucket[value]++;
        
        if(bucket[value] <= 1){
            st.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */