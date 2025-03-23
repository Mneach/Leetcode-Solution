class ProductOfNumbers {
private:
    vector<int> arr;
    int size;
public:
    ProductOfNumbers() {
        arr.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            // need to reset the arr
            arr = {1};
            size = 0;
        } else {
            arr.push_back(arr[size] * num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if (k > size) return 0;

        return arr[size] / arr[size - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */