class Node{
    public:
    int count;
    Node* next;
    Node* prev;
    unordered_set<string> keys;

    Node(int count){
        this -> count = count;
        next = nullptr;
        prev = nullptr;
    }
};

class AllOne {
    private:
    Node* head;
    Node* tail;
    unordered_map<string, Node*> ump;
public:
    AllOne() {
        head = tail = new Node(0);
        head -> next = tail;
        tail -> prev = head;
    }
    
    void inc(string key) {
        
        if(ump[key] == nullptr){
            Node* currentNext = head -> next;
            if(currentNext == tail || currentNext -> count > 1){
                // head - tail
                // become head - new node - tail                
                Node* newNode = new Node(1);
                newNode -> keys.insert(key);
                newNode -> prev = head;
                newNode -> next = currentNext;
                head -> next = newNode;
                currentNext -> prev = newNode;
                ump[key] = newNode;
            }else{
                currentNext -> keys.insert(key);
                ump[key] = currentNext;                
            }
        }else{
            Node *current = ump[key];
            int count = current -> count;
            current -> keys.erase(key);

            Node* currentNext = current -> next;
            if(currentNext == tail || currentNext -> count != count + 1){
                // we are in the same count 
                // or we are in this condition (head - tail)
                Node* newNode = new Node(count + 1);
                newNode -> keys.insert(key);
                newNode -> prev = current;
                newNode -> next = currentNext;
                current -> next = newNode;
                currentNext -> prev = newNode;
                ump[key] = newNode;                
            }else{
                currentNext -> keys.insert(key);
                ump[key] = currentNext;
            }

            if(current -> keys.empty()){
                Node* prevNode = current -> prev;
                Node* nextNode = current -> next;
                prevNode -> next = nextNode;
                nextNode -> prev = prevNode;   
                delete current;             
            }
        }
    }
    
    void dec(string key) {
        if(ump[key] == nullptr) return;

        Node *current = ump[key];
        int count = current -> count;
        current -> keys.erase(key);

        if(count == 1){
            // delete from the map
            ump.erase(key);
        }else{
            Node* currentPrev = current -> prev;
            if(currentPrev == head || currentPrev -> count != count - 1){
                // head - current(count = 2) - Tail
                Node* newNode = new Node(count - 1);
                newNode -> keys.insert(key);
                newNode -> prev = currentPrev;
                newNode -> next = current;
                currentPrev -> next = newNode;
                current -> prev = newNode;
                ump[key] = newNode;
            }else{
                
                // move to the prev
                currentPrev -> keys.insert(key);
                ump[key] = currentPrev;
            }
        }

        if(current -> keys.empty()){
            // remove current node
            Node* prevNode = current -> prev;
            Node* nextNode = current -> next;
            prevNode -> next = nextNode;
            nextNode -> prev = prevNode;

            delete current;
        }
    }
    
    string getMaxKey() {
        if(tail == nullptr || tail -> prev == head) return "";

        return *(tail -> prev -> keys.begin());
    }
    
    string getMinKey() {
        if(head == nullptr || head -> next == tail) return "";

        return *(head -> next -> keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */