package test_java_lab;

import student.Student;

public class TestStudent {

    public static void main() {
        Date d1 = new Date(1,1, 2001);
        Date d2 = new Date(10,1, 2005);
        Student s = new Student(1, "Name", 12, d1, d2);
    }
}