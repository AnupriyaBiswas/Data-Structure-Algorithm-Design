import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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
            
                System.out.println("Area of Triangle: " + calculator.area(a, b, c));
                break;
            case 2:
                System.out.print("Enter Length  : ");
                double len = Double.parseDouble(br.readLine());
                System.out.print("Enter Breadth : ");
                double brd = Double.parseDouble(br.readLine());
        
                System.out.println("Area of Rectangle: " + calculator.area(len, brd));
                break;

            case 3:
                System.out.print("Enter Side  : ");
                double s = Double.parseDouble(br.readLine());
        
                System.out.println("Area of Square : " + calculator.area(s));
                break;

            case 4:
                System.out.print("Enter Side  : ");
                int r = Integer.parseInt(br.readLine());
        
                System.out.println("Area of Circle : " + calculator.area(r));
                break;

            default: 
                System.out.println("Sorry, Wrong Choice.");
                break;
        }
    }
}
