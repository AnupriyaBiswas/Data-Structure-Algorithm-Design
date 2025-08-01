class Prog9002i {

    // Method to calculate the area of a triangle
    public double area(double base, double height) {
        return 0.5 * base * height;
    }

    // Method to calculate the area of a rectangle
    public double area(double length, double width) {
        return length * width;
    }

    // Method to calculate the area of a square
    public double area(double side) {
        return side * side;
    }

    // Method to calculate the area of a circle
    public double area(int radius) {
        return Math.PI * radius * radius;
    }

    public static void main(String[] args) {
        Prog9002i calculator = new Prog9002i();

        System.out.println("Area of Triangle: " + calculator.area(5.0, 10.0));
        System.out.println("Area of Rectangle: " + calculator.area(4.0, 8.0));
        System.out.println("Area of Square: " + calculator.area(6.0));
        System.out.println("Area of Circle: " + calculator.area(7));
    }
}
