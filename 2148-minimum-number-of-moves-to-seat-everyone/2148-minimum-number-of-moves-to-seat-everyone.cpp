class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int answer = 0;

        for(int i = 0; i < students.size(); i++){
            int seat = seats[i];
            int student = students[i];

            answer += abs(student - seat);
        }

        return answer;
    }
};