class Solution {
public:

vector<string> WEEKDAYS = {
    "Sunday", "Monday", "Tuesday", "Wednesday", 
    "Thursday", "Friday", "Saturday"
};

    string dayOfTheWeek(int day, int month, int year) {
        adjustYearAndMonthForAlgorithm(month, year);
        
        const int century = year / 100;
        const int yearInCentury = year % 100;
        
        const int weekdayIndex = computeWeekdayIndex(day, month, century, yearInCentury);
        return WEEKDAYS[(weekdayIndex + 7) % 7];
    }

private:

    void adjustYearAndMonthForAlgorithm(int& month, int& year) const {
        if (month < 3) {
            month += 12;
            year -= 1;
        }
    }

    int computeWeekdayIndex(int day, int month, int century, int yearInCentury) const {
        return (century / 4 - 2 * century + yearInCentury + yearInCentury / 4 + 
                13 * (month + 1) / 5 + day - 1) % 7;
    }
};