// Write a program to return area of triangle, rectangle, square and circle using Function Overloading.

import java.io.*;
class Prog9001i {

    // Method to calculate the area of a triangle
    public double area(double a, double b, double c) {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    // Method to calculate the area of a rectangle
    public double area (double length, double width) 
    {
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

    public static void main(String[] args)throws IOException 
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader (isr);

        Prog9001i calculator = new Prog9001i();

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
