public class FactoryDesignPattern
{
	public static void main(String[] args){
		java.util.Scanner sc= new java.util.Scanner(System.in);
		OperatingSystemFactory osf = new OperatingSystemFactory();
		osInterface obj = osf.getOSInstance(sc.nextLine());
		obj.spec();
	}
}