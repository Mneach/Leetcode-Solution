/*

How to solve the problem : 
1. Save the value in hashtable with key = number and value = index in the array
2. Everytime thee function insert called by another object, we need to check 
   - if the current number is already exists in hashtable then we just need to return false
   - otherwise put the number into the array, and put that number into the hashtable key = number and value = array.size() - 1. Then return true
3. Evertyime the function remove called by another objcet, we need to check
   - if the current val is already exists in the hashtable, then
     - remove the current number from hashtbale
     - if the array size >= 1, then we need to get the last element of the array and put that into the index that we want to delete we also need to updat the hashtable value for that element
     - otherwise do nothing
     - return true
   - otherwise return false


*/

class RandomizedSet {
private:
    unordered_map<int,int> hashTable;
    vector<int> array;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (hashTable.count(val) > 0) {
            return false;
        } else {
            // put the data into the hashtable
            hashTable[val] = array.size();
            array.push_back(val);
            return true;
        }        
    }
    
    bool remove(int val) {
        if (hashTable.count(val) > 0) {
            int number = val;
            int index = hashTable[number];

            if (array.size() > 1) {
                int lastElement = array[array.size() - 1];

                // update current array value with the last element
                array[index] = lastElement;

                // update hashtable value
                hashTable[lastElement] = index;
            }

            hashTable.erase(number);
            array.pop_back();
            return true;
        } else {
            return false;
        }
    }
    
    int getRandom() {
        int maxValue = array.size();
        int random = rand() % maxValue;

        return array[random]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */