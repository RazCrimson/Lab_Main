package mathdatatypes;

import java.util.Objects;

public class ComplexNumber {
    double real, imaginary;

    public ComplexNumber() {
        real = 0;
        imaginary = 0;
    }

    public ComplexNumber(double rl, double img) {
        real = rl;
        imaginary = img;
    }

    public static ComplexNumber add(ComplexNumber c1, ComplexNumber c2) {
        return new ComplexNumber(c1.real + c2.real, c1.imaginary + c2.imaginary);
    }

    public static ComplexNumber subtract(ComplexNumber c1, ComplexNumber c2) {
        return new ComplexNumber(c1.real - c2.real, c1.imaginary - c2.imaginary);
    }

    public static ComplexNumber multiply(ComplexNumber c1, ComplexNumber c2) {
        double realPart = (c1.real * c2.real) + (c1.imaginary * c2.imaginary);
        double imgPart = (c1.real * c2.imaginary) + (c2.real * c1.imaginary);
        return new ComplexNumber(realPart, imgPart);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        ComplexNumber complex = (ComplexNumber) o;
        return Double.compare(complex.real, real) == 0 && Double.compare(complex.imaginary, imaginary) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(real, imaginary);
    }

    public double getReal() {
        return real;
    }

    public void setReal(double real) {
        this.real = real;
    }

    public double getImaginary() {
        return imaginary;
    }

    public void setImaginary(double imaginary) {
        this.imaginary = imaginary;
    }

    public void add(ComplexNumber c) {
        real += c.real;
        imaginary += c.imaginary;
    }

    public void subtract(ComplexNumber c) {
        real -= c.real;
        imaginary -= c.imaginary;
    }

    public void multiply(ComplexNumber c) {
        double realPart = (real * c.real) + (imaginary * imaginary);
        double imgPart = (real * c.imaginary) + (c.real * imaginary);
        real = realPart;
        imaginary = imgPart;
    }

    public String toString() {
        if (imaginary > 0)
            return real + "+" + imaginary + "i";
        return real + "" + imaginary + "i";
    }

}
