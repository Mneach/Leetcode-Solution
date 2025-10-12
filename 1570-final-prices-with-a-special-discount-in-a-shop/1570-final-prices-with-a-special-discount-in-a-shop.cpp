/*

How to solve the problem

# Using stack 
1. initialize class
   - Price
2. initialize variables
   - stack<Price> stackPrices
   - vector<int> results
3. loop from the first index of prices until last index of prices
   - curerntPrice = prices[i]
   - priceDataFromStack;
   - while (stackPrices.size() > 0 && stackPrices.top().getValue() >= prices[i])
     - priceDataFromStack = stackPrices.top()
     - stackPrices.pop()
     - int pay = priceDataFromStack.getValue() - currentPrice
     - int index = priceDataFromStack.getIndex()
     - results[index] = pay
4. while stackPrices.empty() == false
   - priceDataFromStack = stackPrices.top()
   - stackPrices.pop()
   - int pay = priceDataFromStack.getPrice()
   - int index = priceDataFromStack.getIndex(0)
   - results[index] = pay
   - stackPrices.pop()
5. return results

Time Complexity : O(N + M)
N -> size of prices
M -> size of stacks

Memory Complexity : O(M)
M -> size of stacks

*/

class Price {
private: 
    int value;
    int index;
public:
    Price(int value, int index) {
        this -> value = value;
        this -> index = index;
    }

    int getValue() {
        return this -> value;
    }

    int getIndex() {
        return this -> index;
    }
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<Price> stackPrices;      
        vector<int> results(prices.size(), 0);

        for (int i = 0; i < prices.size(); i++) {
            int currentPrice = prices[i];

            while (stackPrices.size() > 0 && stackPrices.top().getValue() >= currentPrice) {
                Price priceFromStack = stackPrices.top();
                stackPrices.pop();
                int pay = priceFromStack.getValue() - currentPrice;
                int index = priceFromStack.getIndex();
                results[index] = pay;
            }

            stackPrices.push({currentPrice, i});
        }

        while (stackPrices.size() > 0) {
            Price priceFromStack = stackPrices.top();
            stackPrices.pop();
            int pay = priceFromStack.getValue();
            int index = priceFromStack.getIndex();
            results[index] = pay;
        }

        return results;
    }
};