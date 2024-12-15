
class Node {
public:
    double avg;
    int pass;
    int total;

    Node(double avg, int pass, int total) {
        this -> avg = avg;
        this -> pass = pass;
        this -> total = total;
    }


};

struct Compare {
public:
    bool operator()(Node &first, Node& second) {
        int firstPass = first.pass + 1;
        int firstTotal = first.total + 1;
        int secondPass = second.pass + 1;
        int secondTotal = second.total + 1;
        double firstAvg = (double) firstPass / firstTotal;
        double secondAvg = (double) secondPass / secondTotal;

        double diffFirstAvg = firstAvg - first.avg;
        double diffSecondAvg = secondAvg - second.avg;

        return diffFirstAvg < diffSecondAvg;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Node, vector<Node>, Compare> pq;
        double answer = 0;

        for (auto c : classes) {
            int pass = c[0];
            int total = c[1];

            double avg = (double) pass / total;
            pq.push(Node(avg, pass, total));
        }

        while (extraStudents > 0) {
            auto node = pq.top();
            pq.pop();
            int pass = node.pass + 1;
            int total = node.total + 1;
            double avg = (double) pass / total;

            pq.push(Node(avg, pass, total));
            extraStudents--;
        }

        while (pq.size() > 0) {
            auto node = pq.top();
            pq.pop();
            // cout << node.avg << " " << node.pass << " " << node.total << endl;
            answer += node.avg;
        }

        return answer / classes.size();
    }
};





