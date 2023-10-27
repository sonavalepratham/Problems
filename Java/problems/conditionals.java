import java.util.Scanner;
public class conditionals {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt(), b=sc.nextInt();
        if(a<b){
            System.out.println("1st block");
        }
        else if(a==b){
            System.out.println("2nd block");
        }
        else System.out.println("Third block");

        int age = sc.nextInt();
        
        switch(age){
            case 18:
            System.out.println("you are 18");
            break;
            case 19:
            System.out.println("you are 19");
            break;
            default:
            System.out.println("you are ::");
        }
        
        while(a<b){
            a++;
        }
        
        do{
            b++;
        }while(b<a);
        
        for(int i=0; i<5; i++){
            System.out.println("hello");
        }
        sc.close();
    }
}
