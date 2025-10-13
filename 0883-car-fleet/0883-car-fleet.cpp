
/*

How to solve the problem

# Using stack + sorting
1. create a class (Car)
   - int position
   - int speed
2. initialize variables
   - stack<int> stack
3. sort the cars data by position asc
4. loop from the first index of cars array until last index of cars array
   - count total iteration that we need to reach finish 
     - totalIteration = (target - cars[i].getPosition()) / cars[i].getSpeed()
     - while (stack.size() > 0 && stack.top() <= totalIteration)
       - stack.pop()
   - push totalIteration into the stack
5. return stack.size()

Time Complexity : O(N log N + N)
N -> size of cars array

Memory Complexity : O(N + M)
N -> size of cars array
M -> size of stack

*/

class Car {
private:
    int position;
    int speed;
public:
    Car(int position, int speed) {
        this -> position = position;
        this -> speed = speed;
    }

    int getPosition() {
        return this -> position;
    }

    int getSpeed() {
        return this -> speed;
    }
};


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        stack<double> stack;

        for (int i = 0; i < position.size(); i++) {
            Car car = Car(position[i], speed[i]);
            cars.push_back(car);
        }

        sort(cars.begin(), cars.end(), [](Car a, Car b){ 
            return a.getPosition() > b.getPosition();
        });

        for (int i = 0; i < cars.size(); i++) {
            double time = (1.0 * target - cars[i].getPosition()) / cars[i].getSpeed();

            if (stack.size() == 0 || stack.top() < time) {
                stack.push(time);
            }
        }

        return stack.size();
    }
};