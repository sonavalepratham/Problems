import java.util.*;
import java.io.*;

class WeiredAlgorithem {
    
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
  
        if (System.getProperty("ONLINE_JUDGE") == null) {
            
            try {
                System.setOut(new PrintStream(
                    new FileOutputStream("output.txt")));
                sc = new Scanner(new File("input.txt"));
            }
  
            catch (Exception e) {
            }
        }

        Long n = sc.nextLong();
 
        while(n>1)
        {
        	if(n%2==0)
        	{
        		System.out.print(n+" ");
        		n=n/2;
        	}
       		else
       		{
       			System.out.print(n+" ");
       			n=(n*3)+1;
       		}
       		
        }
        System.out.print(1);
    }
}