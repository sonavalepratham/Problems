public class OperatingSystemFactory
{
	public osInterface getOSInstance(String os){
		switch(os){
			case "Android":
				return new Android();
			case "Windows":
				return new Windows();
			default: return null;
		}
	}
}