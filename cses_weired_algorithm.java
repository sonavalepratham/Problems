import java.io.*;

import java.util.*;
  
class cp_template {
    
    public static void main(String[] args)
    {
        Scanner read = new Scanner(System.in);
  
        if (System.getProperty("ONLINE_JUDGE") == null) {
            
            try {
                System.setOut(new PrintStream(
                    new FileOutputStream("outputf.in")));
                read = new Scanner(new File("inputf.in"));
            }
  
            catch (Exception e) {
            }
        }
        Int n=read.nextInt();
        while(n!=1){
        	if(n%2==0){
        		System.out.print(n+" ");
        		n/=2;
        	}
        	else{
        		System.out.print(n+" ");
        		n=n*3+1;
        	}
        }
        System.out.print(n);
    }
}