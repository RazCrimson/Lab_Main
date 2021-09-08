package test_java_lab;

public class Date {
    int day, month, year;
    static int[] daysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

    public Date(int d, int m, int y) {
        setDate(d, m, y);
    }

    public Date(Date date) {
        setDate(date.day, date.month, date.year);
    }

    private boolean validDate(int d, int m, int y) {
        if (year < 1990 || m > 12 || m < 1)
            return false;
        if (d < 0 || d > daysOfMonth[m - 1] || (m == 2 && y % 4 == 0 && d > 29))
            return false;
        return true
    }

    public void setDate(int d, int m, int y) {
        if (!validDate(d, m, y)
            System.out.println("Error")
        day = d;
        month = m;
        year = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!o instanceof Date) return false;
        Date date = (Date) o;
        return day == date.day && month == date.month && year == date.year;
    }

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }

    @Override
    public String toString() {
        return day + "/" + month + "/" + year;
    }

    public int compare(Date date) {
        if (year != date.year) return year < date.year ? 1 : -1;
        if (month != date.month) return month < date.month ? 1 : -1;
        if (day != date.day) return day < date.day ? 1 : -1;
        return 0;
    }

    public int diff(Date date) {
        if (compare(date) != -1)
            return 0;

        int differenceDays = 0;
        Date d = new Date(date);

        while (year - 1 > d.year)){
            d.year += 1;
            differenceDays += 365;
            if (d.year % 4 == 0)
                differenceDays += 1;
        }

        while (year > d.year || month - 1 > d.month)){
            d.month += 1;
            if (d.month > 12) {
                d.month = 1;
                d.year += 1;
            }
            differenceDays += daysOfMonth[d.month - 1];
            if (d.month == 2)
                differenceDays += 1;
        }

        while (day > d.day) {
            d.day += 1;
            differenceDays += 1;
            if ((month == 2 && d.day > 29) || (month != 2 && d.day > daysOfMonth[month - 1]) {
                d.day = 1;
                month += 1;
            }
        }
    }

    public Date addDays(int days){
        Date d = new Date(this);
        while(days){
            if(days > daysOfMonth[d.month - 1]){
                month += 1;
                days -= da
                if(month > 12){
                    year += 1;
                }
            }
            else{
                d.day += 1;
                days -= 1;
                if ((month == 2 && d.day > 29) || d.day > daysOfMonth[month - 1]) {
                    d.day = 1;
                    month += 1;
                }
            }
        }
    }
}
