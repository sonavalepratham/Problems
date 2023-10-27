import java.io.*;

import java.util.*;
  
class towerofhanoi {
    static ArrayList<ArrayList<Integer>> list=new ArrayList<ArrayList<Integer>>();
    static void fun(int n, Integer a, Integer c, Integer b){
    if(n==0) return;
    fun(n-1, a, b, c);
    list.add(new ArrayList<Integer>(Arrays.asList(a, c)));
    fun(n-1, b, c, a);
  }
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
  
        int inp = read.nextInt();
        fun(inp, 1, 3, 2);
        System.out.println(list.size());
        for(int i=0; i<list.size(); i++){
            System.out.println(list.get(i).get(0)+ " " +list.get(i).get(1));
        }
    }
}
