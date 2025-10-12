/*

How to solve the problem

# Using stack
1. initialize class Data
   - price
   - result
2. initialize stack
   - stack<Data> stack
3. next functions
   - result = 1 
   - while (stack.size() > 0 && stack.top.getPrice() <= price) 
     - stack.pop();
     - result++
   - stack.push(new Data(price, result))
   - return result

*/

class Data {
private:
    int price;
    int result;
public:
    Data(int price, int result) {
        this -> price = price;
        this -> result = result;
    }

    int getResult() {
        return this -> result;
    }

    int getPrice() {
        return this -> price;
    }
};

class StockSpanner {
private:
    stack<Data> stack;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int result = 1;

        while (stack.size() > 0 && stack.top().getPrice() <= price) {
            result += stack.top().getResult();
            stack.pop();
        }

        stack.push(Data(price, result));

        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */