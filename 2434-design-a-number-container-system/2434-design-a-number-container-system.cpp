class NumberContainers {
private:
    unordered_map<int,int> bucket;
    unordered_map<int,set<int>> container; 

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if (bucket[index] > 0) {
            int currentIndex = index;
            int currentNumber = bucket[index];

            container[currentNumber].erase(currentIndex);

            if (container[currentNumber].size() == 0) {
                container.erase(currentNumber);
            }
        }
        
        container[number].insert(index);
        bucket[index] = number;
    }
    
    int find(int number) {
        return container[number].size() > 0 ? *container[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */