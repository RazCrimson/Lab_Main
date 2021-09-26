package student_date;

import java.util.ArrayList;
import java.util.List;

public class Student {

    int rollNumber, age;
    String firstName, lastName;
    Date birthDate, joinDate;

    Student(int rollNumber, String fName, String lName, int age, Date birthDate,
            Date joinDate) {
        if (birthDate.compare(joinDate) == -1) {
            System.out.println("Invalid Departure Date");
            // throw err
        }

        this.rollNumber = rollNumber;
        this.firstName = fName;
        this.lastName = lName;
        this.age = age;
        this.birthDate = new Date(birthDate);
        this.joinDate = new Date(joinDate);
    }

    public static void main(String[] args) {
        Date d1 = new Date(1, 1, 2001);
        Date d2 = new Date(10, 1, 2005);
        List<Student> l = new ArrayList<Student>();

        for (int i = 0; i < 4; i++) {
            l.add(new Student(i + 1, "fName" + i, "lName" + i, 15, d1, d2));
        }

        for (Student s : l) {
            System.out.println(s);
        }

    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (!(o instanceof Student)) {
            return false;
        }
        Student s = (Student) o;
        return rollNumber == s.rollNumber && firstName.equals(s.firstName)
                && lastName.equals(s.lastName) && age == s.age
                && birthDate.equals(s.birthDate) && joinDate.equals(s.joinDate);
    }

    @Override
    public String toString() {

        return "Student(" + rollNumber + "," + firstName + "," + lastName + ","
                + age + "," + birthDate + "," + joinDate + ")";
    }

    public int getRollNumber() {
        return rollNumber;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getAge() {
        return age;
    }

    public Date getBirthDate() {
        return new Date(birthDate);
    }

    public Date getJoinDate() {
        return new Date(joinDate);
    }
}
