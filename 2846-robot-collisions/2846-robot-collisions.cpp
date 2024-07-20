class Robot{
public:

    int health;
    int index;
    int position;

    Robot(int health, int index, int position){
        this->health = health;
        this->index = index;
        this->position = position;
    }
};

struct positionComparatorDesc{
    bool operator()(const Robot r1, const Robot r2){
        return r1.position < r2.position;
    }
};

struct positionComparatorAsc{
    bool operator()(const Robot r1, const Robot r2){
        return r1.position > r2.position;
    }
};

void printRobot(priority_queue<Robot, vector<Robot>, positionComparatorDesc> robots){
    while(robots.size() > 0){
        auto data = robots.top();
        robots.pop();
        cout << data.health << " " << data.index << " " << data.position << endl;
    }

    cout << endl;
}

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        priority_queue<Robot, vector<Robot>, positionComparatorDesc> leftRobot;
        priority_queue<Robot, vector<Robot>, positionComparatorDesc> rightRobot;
        stack<Robot> bucketLeft;

        vector<int> answer;
        vector<Robot> tempAnswer;

        for(int i = 0; i < positions.size(); i++){
            int position = positions[i];
            int health = healths[i];
            char direction = directions[i];

            if(direction == 'R'){
                rightRobot.push(Robot(health, i, position));
            }else{
                leftRobot.push(Robot(health,i,position));
            }
        }

        // printRobot(rightRobot);
        // cout << endl;
        // printRobot(leftRobot);

        while(leftRobot.size() > 0 && rightRobot.size() > 0){
            Robot left = leftRobot.top();
            Robot right = rightRobot.top();

            if(right.position < left.position){
                bucketLeft.push(left);
                leftRobot.pop();
            }else if(right.position > left.position && bucketLeft.size() != 0){
                Robot bucketRobot = bucketLeft.top();
                
                bucketLeft.pop();
                rightRobot.pop();

                // compare
                if(right.health > bucketRobot.health){
                    right.health -= 1;
                    rightRobot.push(right);
                }else if(right.health < bucketRobot.health){
                    bucketRobot.health -= 1;
                    bucketLeft.push(bucketRobot);
                }
            }else{
                tempAnswer.push_back(right);
                rightRobot.pop();
            }
        }

        while(rightRobot.size() > 0 && bucketLeft.size() > 0){
            Robot right = rightRobot.top();
            Robot bucketRobot = bucketLeft.top();

            rightRobot.pop();
            bucketLeft.pop();

            // compare
            if(right.health > bucketRobot.health){
                right.health -= 1;
                rightRobot.push(right);
            }else if(right.health < bucketRobot.health){
                bucketRobot.health -= 1;
                bucketLeft.push(bucketRobot);
            }            
        }

        while(rightRobot.size() > 0){
            tempAnswer.push_back(rightRobot.top());
            rightRobot.pop();
        }

        while(bucketLeft.size() > 0){
            tempAnswer.push_back(bucketLeft.top());
            bucketLeft.pop();
        }

        while(leftRobot.size() > 0){
            tempAnswer.push_back(leftRobot.top());
            leftRobot.pop();
        }

        sort(tempAnswer.begin(), tempAnswer.end(), [](const Robot& r1, const Robot& r2){
            return r1.index < r2.index;
        });

        for(auto robot : tempAnswer){
            answer.push_back(robot.health);
        }

        return answer;
    }
};