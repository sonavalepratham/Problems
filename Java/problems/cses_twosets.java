import java.util.*;
import java.io.*;

class TwoSets {
    
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

        int n =  sc.nextInt();
        if(n<3)
        	System.out.println("NO");
        else
        { 
        
        int sum = n*(n+1)/2;
        int sum2=0;
        int no=n;
        int j=n;
        ArrayList l= new ArrayList();
        if(sum % 2 ==0)
        {
        	System.out.println("YES");

        	for(int i=1;i<n;i++)
        	{	
        		sum2 = sum2 + i; 
        		if(sum2<=sum/2)
        		{    
        			l.add(i);  			
            		if((sum/2)-sum2 >= n)
        			{
	       				sum2=sum2+n;  
        				l.add(n);
        				n--;
        			}
        			if((sum/2)-sum2 < n && (sum/2)-sum2!=0)
        			{
        				l.add((sum/2)-sum2);
        				break;
        			}
    			

        		}
        		if(sum2==sum)
        			break;
       
        	}
        	System.out.println(l.size());
        	for(int i=0;i<l.size();i++)
        		System.out.print(l.get(i)+" ");
        	System.out.println();
        	System.out.println(no-l.size());
        	for(int i=1;i<=n;i++)
        	{
        		if(l.contains(i) == false)
        			System.out.print(i+" ");
        	}
        }
        else
        	System.out.println("NO");
    	}
    }
}