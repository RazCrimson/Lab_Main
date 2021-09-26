package student_date;

public class ExchangeStudent extends Student {

    Date departureDate;
    String programme, country, university;

    ExchangeStudent(int rollNumber, String fName, String lName, int age, Date birthDate,
                    Date joinDate, Date departDate, String programme, String country, String university) {
        super(rollNumber, fName, lName, age, birthDate, joinDate);

        if (joinDate.compare(departureDate) == -1) {
            System.out.println("Invalid Departure Date");
            // throw err
        }
        this.departureDate = departDate;
        this.programme = programme;
        this.country = country;
        this.university = university;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (!(o instanceof ExchangeStudent)) {
            return false;
        }
        ExchangeStudent s = (ExchangeStudent) o;
        return rollNumber == s.rollNumber && firstName.equals(s.firstName)
                && lastName.equals(s.lastName) && age == s.age
                && birthDate == s.birthDate && joinDate == s.joinDate
                && departureDate == s.departureDate && programme.equals(s.programme)
                && country.equals(s.country) && university.equals(university);

    }

    @Override
    public String toString() {

        return "ExchangeStudent(" + rollNumber + "," + firstName + "," + lastName + ","
                + age + "," + birthDate + "," + joinDate + "," + departureDate
                + "," + programme + "," + country + "," + university + ")";
    }

    public Date getDepartureDate() {
        return new Date(departureDate);
    }

    public String getCountry() {
        return country;
    }

    public String getUniversity() {
        return university;
    }

    public String getProgramme() {
        return programme;
    }

    public int getExchangeDuration() {
        return departureDate.diff(joinDate);
    }

}
