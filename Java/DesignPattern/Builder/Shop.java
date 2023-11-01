import com.phone.Phone;
import com.phone.PhoneBuilder;
public class Shop{
	public static void main(String a[]){
		Phone P = new PhoneBuilder().setram(8).build();
		System.out.println(P);
	}
}
