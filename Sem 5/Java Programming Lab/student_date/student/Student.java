package test_java_lab;

import date.Date;

public class Student {
    int rollNumber, age
    String name;
    Date DOB, DOJ;

    Student(int rollNumber, String name, int age, Date birth, Date join) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.age = age;
        this.DOB = new Date(birth);
        this.DOJ = new Date(join);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!o instanceof Student) return false;
        Student s = (Date) o;
        return day == date.day && month == date.month && year == date.year;
    }

    @Override
    public String toString() {
        return "Student(" + rollNumber + "," + name + "," + age + "," + DOB + "," + DOJ + ")";
    }
}