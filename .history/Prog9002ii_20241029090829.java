class Shape {
    public double area() {
        return 0;  // Base class method, should be overridden
    }
}

// Triangle subclass
class Triangle extends Shape {
    private double base, height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    public double area() {
        return 0.5 * base * height;
    }
}

// Rectangle subclass
class Rectangle extends Shape {
    private double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double area() {
        return length * width;
    }
}

// Square subclass
class Square extends Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    @Override
    public double area() {
        return side * side;
    }
}

// Circle subclass
class Circle extends Shape {
    private int radius;

    public Circle(int radius) {
        this.radius = radius;
    }

    @Override
    public double area() {
        return Math.PI * radius * radius;
    }
}

// Main class to test function overriding
public class Prog9002ii {
    public static void main(String[] args) {
        Shape triangle = new Triangle(5.0, 10.0);
        Shape rectangle = new Rectangle(4.0, 8.0);
        Shape square = new Square(6.0);
        Shape circle = new Circle(7);

        System.out.println("Area of Triangle: " + triangle.area());
        System.out.println("Area of Rectangle: " + rectangle.area());
        System.out.println("Area of Square: " + square.area());
        System.out.println("Area of Circle: " + circle.area());
    }
}
