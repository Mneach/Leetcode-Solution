class Solution {
public:
    int dayOfYear(string date) {
        const int year = stoi(date.substr(0, 4));
        const int month = stoi(date.substr(5, 2));
        const int day = stoi(date.substr(8, 2));
        
        const vector<int> days_in_month = getDaysInMonth(year);
        int day_of_year = day;
        
        for (int i = 0; i < month - 1; ++i) {
            day_of_year += days_in_month[i];
        }
        
        return day_of_year;
    }

private:
    vector<int> getDaysInMonth(int year) const {
        vector<int> days = {31, 28, 31, 30, 31, 30, 
                            31, 31, 30, 31, 30, 31};
        
        if (isLeapYear(year)) {
            days[1] = 29;
        }
        
        return days;
    }

    bool isLeapYear(int year) const {
        return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    }
};