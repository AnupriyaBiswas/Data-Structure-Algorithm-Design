import java.io.*;

class Shape {
    public double area() {
        return 0;  // Base class method, should be overridden
    }
}

// Triangle subclass
class Triangle extends Shape 
{
    private double a, b, c;

    public Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    public double area() {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
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
    public static void main(String[] args)throws IOException 
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader (isr);

        Prog9002i calculator = new Prog9002i();

        System.out.println("\nOptions : ");
        System.out.println("1 :: Triangle");
        System.out.println("2 :: Rectangle");
        System.out.println("3 :: Square");
        System.out.println("4 :: Circle\n");
        
        int choice;
        System.out.print("Enter Choice : ");
        choice = Integer.parseInt(br.readLine());

        switch (choice)
        {
            case 1:
                System.out.print("Enter Side 1 : ");
                double a = Double.parseDouble(br.readLine());
                System.out.print("Enter Side 2 : ");
                double b = Double.parseDouble(br.readLine());
                System.out.print("Enter Side 3 : ");
                double c = Double.parseDouble(br.readLine());;

                Shape triangle = new Triangle(a, b, c);
                System.out.println("Area of Triangle : " + triangle.area());
                break;
            case 2:
                System.out.print("Enter Length  : ");
                double len = Double.parseDouble(br.readLine());
                System.out.print("Enter Breadth : ");
                double brd = Double.parseDouble(br.readLine());
        
                Shape rectangle = new Rectangle(len, brd);
                System.out.println("Area of Rectangle : " + rectangle.area());
                break;

            case 3:
                System.out.print("Enter Side  : ");
                double s = Double.parseDouble(br.readLine());
        
                Shape square = new Square(s);
                System.out.println("Area of Square : " + square.area());
                break;

            case 4:
                System.out.print("Enter Side  : ");
                int r = Integer.parseInt(br.readLine());
            
                Shape circle = new Circle(r);
                System.out.println("Area of Circle : " + circle.area());
                break;

            default: 
                System.out.println("Sorry, Wrong Choice.");
                break;
        }
    }
}
