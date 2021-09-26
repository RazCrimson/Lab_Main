package student_date;

public class Date {

    static int[] daysOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, month, year;
    String format = "%d/%m/%y";

    public Date(int d, int m, int y) {
        setDate(d, m, y);
    }

    public Date(Date date) {
        setDate(date.day, date.month, date.year);
        format = date.format;
    }

    public static void main(String[] args) {
        Date d1 = new Date(1, 1, 2021);
        Date d2 = new Date(10, 1, 2021);
        System.out.println("D1: " + d1);
        System.out.println("D2: " + d2);
    }

    private boolean validDate(int d, int m, int y) {
        if (y < 1 || m > 12 || m < 1) {
            return false;
        }
        return d >= 1 && (m == 2 || d <= daysOfMonth[m - 1]) && (m != 2 || y % 4 != 0 || d <= 29);
    }

    public void setDate(int d, int m, int y) {
        if (!validDate(d, m, y)) {
            System.out.println("here");
        }
        day = d;
        month = m;
        year = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (!(o instanceof Date)) {
            return false;
        }
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
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < format.length(); i++) {
            if (format.charAt(i) != '%') {
                s.append(format.charAt(i));
                continue;
            }
            i += 1;

            switch (format.charAt(i)) {
                case '%':
                    s.append('%');
                    break;

                case 'd':
                    s.append(day);
                    break;

                case 'm':
                    s.append(month);
                    break;

                case 'y':
                    s.append(year % 100);
                    break;

                case 'D':
                    if (day < 10) {
                        s.append('0');
                    }
                    s.append(month);
                    break;

                case 'M':
                    if (month < 10) {
                        s.append('0');
                    }
                    s.append(month);
                    break;

                case 'Y':
                    s.append(year);
                    break;

//                default:
//                    throw Exception("Invalid Date format");
            }
        }
        return s.toString();
    }

    public int compare(Date date) {
        if (year != date.year) {
            return year < date.year ? 1 : -1;
        }
        if (month != date.month) {
            return month < date.month ? 1 : -1;
        }
        if (day != date.day) {
            return day < date.day ? 1 : -1;
        }
        return 0;
    }

    public int diff(Date date) {
        if (compare(date) != -1) {
            return 0;
        }

        int differenceDays = 0;
        Date d = new Date(date);

        while (year - 1 > d.year) {
            d.year += 1;
            differenceDays += 365;
            if (d.year % 4 == 0) {
                differenceDays += 1;
            }
        }

        while (year > d.year || month - 1 > d.month) {
            d.month += 1;
            if (d.month > 12) {
                d.month = 1;
                d.year += 1;
            }
            differenceDays += daysOfMonth[d.month - 1];
            if (d.month == 2) {
                differenceDays += 1;
            }
        }

        while (day > d.day) {
            d.day += 1;
            differenceDays += 1;
            if ((month == 2 && d.day > 29) || (month != 2 && d.day > daysOfMonth[month - 1])) {
                d.day = 1;
                month += 1;
            }
        }
        return differenceDays;
    }

    public void addDays(int days) {
        Date d = new Date(this);
        while (days > 0) {
            if (days > daysOfMonth[d.month - 1]) {
                month += 1;
                days -= daysOfMonth[month - 1];
                // Needs more work
                if (month > 12) {
                    year += 1;
                }
            } else {
                d.day += 1;
                days -= 1;
                if ((month == 2 && d.day > 29) || d.day > daysOfMonth[month - 1]) {
                    d.day = 1;
                    month += 1;
                }
            }
        }
    }

    public boolean setFormat(String newFormat) {
        for (int i = 0; i < newFormat.length(); i++) {
            if (newFormat.charAt(i) != '%') {
                continue;
            }

            // Fail if no character succeeds `%`
            if (i + 1 >= newFormat.length()) {
                return false;
            }
            i += 1;

            switch (newFormat.charAt(i)) {
                case '%':
                case 'd':
                case 'm':
                case 'y':
                case 'D':
                case 'M':
                case 'Y':
                    continue;
                default:
                    return false;
            }
        }
        format = newFormat;
        return true;
    }
}
