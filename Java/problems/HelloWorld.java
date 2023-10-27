/**
 * HelloWorld
 */
public class HelloWorld {

    public static void main(String[] args){
        B a = new B();
        a.absmethod();
        a.print(1);
    }
}

abstract class A
{
    abstract public void absmethod();
    abstract public void print(int a);
}

class B extends A
{
    public void absmethod(){
        System.out.println("this is abstract method");
    }
    public void print(int a)
    {
        System.out.println(a);
    }
}