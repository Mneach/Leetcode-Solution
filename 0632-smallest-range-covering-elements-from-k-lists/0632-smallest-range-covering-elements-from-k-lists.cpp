
class Node{
public:
    int number;
    int row;
    int col;
    
    Node(int number, int row, int col){
        this -> number = number;
        this -> row = row;
        this -> col = col;
    }
    
    bool operator<(const Node& other) const {
        return number > other.number;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node> pq;
        int n = nums.size();
        int m = nums[0].size();
        int maxVal = INT_MIN;
        vector<int> answer(2, -1);
        answer[0] = 0;
        answer[1] = INT_MAX;

        for(int i = 0; i < n; i++){
            Node node(nums[i][0], i , 0);
            pq.push(node);
            maxVal = max(maxVal, nums[i][0]);
        }

        while(pq.size() == nums.size()){
            auto node = pq.top();
            pq.pop();

            int row = node.row;
            int col = node.col;

            // cout << row << " " << col << endl;

            // calculate the answer
            if(maxVal - node.number < answer[1] - answer[0]){
                answer[0] = node.number;
                answer[1] = maxVal;
            }
            
            if(col + 1 >= nums[row].size()) break;

            // move the current pointer to the next
            pq.push(Node(nums[row][col + 1], row, col + 1));
            
            // update max val
            maxVal = max(maxVal, nums[row][col + 1]);
        }
        
        return answer;
    }
};