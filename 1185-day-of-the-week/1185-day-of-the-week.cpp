class Solution {
public:
    string dayOfTheWeek(int date, int month, int year) {
        vector <string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        unordered_map <int, int> month_days;

        month_days.insert({1,31});
        month_days.insert({2,((year%4==0 && year%100!=0) || (year%400==0) ? 29 : 28)});
        month_days.insert({3,31});
        month_days.insert({4,30});
        month_days.insert({5,31});
        month_days.insert({6,30});
        month_days.insert({7,31});
        month_days.insert({8,31});
        month_days.insert({9,30});
        month_days.insert({10,31});
        month_days.insert({11,30});
        month_days.insert({12,31});

        int year_contri = ((year-1969)*1461)/4;
        int month_contri = 0;

        for (int i=1 ; i<month ; i++)month_contri+=month_days[i];

        return days[(year_contri+month_contri+date+2)%7];
    }
};