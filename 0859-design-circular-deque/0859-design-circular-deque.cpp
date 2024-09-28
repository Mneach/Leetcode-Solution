class MyCircularDeque {
private:
    struct CircularDeque{
        
        CircularDeque *next;
        CircularDeque *prev;
        int value;

        CircularDeque(int value){
            this -> next = nullptr;
            this -> prev = nullptr;
            this -> value = value;
        }
    };

public:

    int max;
    int count;

    CircularDeque* head;
    CircularDeque* tail;

    MyCircularDeque(int k) {
        max = k;
        count = 0;    
        head = nullptr;
        tail = nullptr;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;

        if(head == nullptr && tail == nullptr){
            head = new CircularDeque(value);
            tail = head;
        }else{
            CircularDeque* newNode = new CircularDeque(value);
            tail -> next = newNode;
            newNode -> prev = tail;
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;    
        }

        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        if(head == nullptr && tail == nullptr){
            head = new CircularDeque(value);
            tail = head;
        }else{
            CircularDeque* newNode = new CircularDeque(value);
            tail -> next = newNode;
            newNode -> prev = tail;
            newNode -> next = head;
            head -> prev = newNode;
            tail = newNode;
        }

        count++;
        return true;
    }
    
    bool deleteFront() {
        
        if(isEmpty()) return false;
        if(count == 1){
            head = nullptr;
            tail = nullptr;
        }else{
            CircularDeque* nextNode = head -> next;
            delete head;
            head = nextNode;
        }

        count--;
        return true;        
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(count == 1){
            head = nullptr;
            tail = nullptr;
        }else{
            CircularDeque* prevNode = tail -> prev;
            delete tail;
            tail = prevNode;     
        }

        count--;
        return true;
    }
    
    int getFront() {
        if(head == nullptr || count == 0) return -1;
        return head -> value;
    }
    
    int getRear() {
        if(tail == nullptr || count == 0) return -1;
        return tail -> value;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == max;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */