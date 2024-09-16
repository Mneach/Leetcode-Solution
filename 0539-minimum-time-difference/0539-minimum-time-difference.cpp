class Solution {
private:
    int calculate(string a, string b){
        int hourA = stoi(a.substr(0, 2));
        int minuteA = stoi(a.substr(3, 2));

        int hourB = stoi(b.substr(0, 2));
        int minuteB = stoi(b.substr(3, 2));

        int result = INT_MAX;

        if(hourA != hourB){

            // just calculate the hour and minute
            // but what if hourA > hourB
            // ex : 00:00, 23:59

            if(hourA > hourB){
                hourB += 24;
                minuteB += 60;

                result = (hourB - hourA) * 60 + (minuteB - minuteA);

                if(minuteB > minuteA){
                    result -= 60;
                }
            }else{
                result = (hourB - hourA) * 60 + (minuteB - minuteA);
            }

            // if(minuteB - minuteA == 0){
            //     result += 60;
            // }
        }else{
            // just calculate the minute
            // what if minuteA > minuteB
            // ex : 00:10, 00:20

            if(minuteA > minuteB){
                result = 23 * 60 + ((minuteB + 60) - minuteA);
            }else{
                result = minuteB - minuteA;
            }
        }

        return result; 
    }
    
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        
        int answer = INT_MAX;

        for(int i = 0; i < timePoints.size(); i++){
            string time = timePoints[i];
            int result = 0;

            if(i == timePoints.size() - 1){
                result = calculate(timePoints[i], timePoints[0]);
            }else{
                result = calculate(timePoints[i], timePoints[i + 1]);
            }

            cout << result << endl;

            answer =  min(answer, result);
        }

        return answer;
    }
};