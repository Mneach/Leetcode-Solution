class Node{
public:
    Node* next;
    Node* prev;
    int value;

    Node(int value){
        next = nullptr;
        prev = nullptr;
        this -> value = value;
    }
};

class CustomStack {
public:

    Node* head;
    Node* tail;
    int count;
    int maxSize;

    CustomStack(int maxSize) {
        head = nullptr;
        tail = nullptr;
        this -> count = 0;
        this -> maxSize = maxSize;
    }
    
    void push(int x) {
        if(count == maxSize) return;

        Node* newNode = new Node(x);
        if(head == nullptr){
            head = tail = newNode;
        }else{
            head -> prev = newNode;
            newNode -> next = head;
            head = newNode;
        }

        count++;
    }
    
    int pop() {

        if(head == nullptr){
            return -1;
        }else if(head == tail){
            Node* tempHead = head;
            int value = head -> value;
            delete tempHead;

            head = nullptr;
            tail = nullptr;

            count--;
            return value;
        }else{
            Node* tempHead = head;
            int value = head -> value;
            head = head -> next;
            head -> prev = nullptr;

            delete tempHead;
            count--;
            return value;            
        }
    }
    
    void increment(int k, int val) {
        
        Node* current = tail;
        while(k > 0 && current != nullptr){
            current -> value += val;
            current = current -> prev;
            k--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */