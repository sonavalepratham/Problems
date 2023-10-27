import java.util.Scanner;;
public class IO {
   public static void main(String[] args) {
       Scanner s = new Scanner(System.in); // System.in specifies that we are taking input from keyboard.
    //    System.out.println("Enter 1st number");
    //     int a, b;
    //     a=s.nextInt();
    //     System.out.println("Enter 2nd number");
    //     b=s.nextInt();
    //     System.out.println(a+" "+b);
    int a = s.nextInt();
    System.out.println(a++*3);
    s.close();
   } 
}
