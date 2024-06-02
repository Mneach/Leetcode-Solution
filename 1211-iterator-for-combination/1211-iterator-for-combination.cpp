class CombinationIterator {
public:

    string characters;
    int combinationLength;
    vector<string> bucket;
    int index;

    void recursive(vector<string> &bucket, int combinationLength, string current, string characters, int start){
        if(current.length() == combinationLength){
            bucket.push_back(current);
            return;
        }

        for(int i = start; i < characters.length(); i++){
            recursive(bucket, combinationLength, current + characters[i], characters, i + 1);
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        index = -1;
        this->characters = characters;
        this->combinationLength = combinationLength;
        
        recursive(bucket, combinationLength, "", characters, 0);

        for(auto data : bucket) cout << data << endl;
    }
    
    string next() {
        index++;
        return bucket[index];
    }
    
    bool hasNext() {
        return index < bucket.size() - 1 || index == -1;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */