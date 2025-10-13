
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
     - time = (1.0 * target - cars[i].getPosition()) / cars[i].getSpeed()
     - if stack is empty or stack.top() < time
       - push time into the stack
5. return stack.size()

Time Complexity : O(N log N + N)
N -> size of cars array

Memory Complexity : O(N + M)
N -> size of cars array
M -> size of stack

# Iteration
1. create class Car
2. initialize variables
   - prev time = (1.0 * target - cars[0].getPosition) / cars[i].getSpeed()
   - result = 1
3. loop from the first index of cars array until last index of cars array
   - calculate the current time 
   - if current time > prev time
     - prev time = current time
     - result++
4. return result

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
        int result = 1;

        for (int i = 0; i < position.size(); i++) {
            Car car = Car(position[i], speed[i]);
            cars.push_back(car);
        }

        sort(cars.begin(), cars.end(), [](Car a, Car b){ 
            return a.getPosition() > b.getPosition();
        });

        double prevTime = (1.0 * target - cars[0].getPosition()) / cars[0].getSpeed();

        for (int i = 1; i < cars.size(); i++) {
            double currentTime = (1.0 * target - cars[i].getPosition()) / cars[i].getSpeed();

            if (currentTime > prevTime) {
                prevTime = currentTime;
                result++;
            }
        }

        return result;
    }
};