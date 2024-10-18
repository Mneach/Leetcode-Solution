class FirstUnique {
public:

    unordered_map<int,int> bucket;
    unordered_map<int,bool> notUnique;
    queue<int> st;
    FirstUnique(vector<int>& nums) {
        for(auto number : nums){
            st.push(number);
            bucket[number]++;
            if(bucket[number] > 1){
                notUnique[number] = true;
            }
        }    
    }
    
    int showFirstUnique() {
        while(st.size() > 0 && notUnique[st.front()] == true){
            st.pop();
        }

        if(st.size() == 0) return -1;
        else return st.front();
    }
    
    void add(int value) {
        bucket[value]++;
        if(bucket[value] > 1){
            notUnique[value] = true;
        }

        if(notUnique[value] == false){
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