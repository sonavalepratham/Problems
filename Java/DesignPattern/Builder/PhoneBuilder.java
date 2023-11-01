package com.phone;
public class PhoneBuilder{
	private String OS;
    private int ram;
    private String processor;
    private double screenSize;
    private int battery;
	
	public PhoneBuilder setOS(String os)
	{
		this.OS=os;
		return this;
	}
	public PhoneBuilder setram(int ram)
	{
		this.ram=ram;
		return this;
	}
	public PhoneBuilder setprocessor(String processor)
	{
		this.processor=processor;
		return this;
	}
	public PhoneBuilder setscreenSize(double screenSize)
	{
		this.screenSize=screenSize;
		return this;
	}
	public PhoneBuilder setbattery(int battery)
	{
		this.battery=battery;
		return this;
	}
	
	public Phone build(){
		return new Phone(OS, ram, processor, screenSize, battery);
	}
}