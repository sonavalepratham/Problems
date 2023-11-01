package com.springrest.springrest.controller.entity;

public class Course {
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public long getId() {
		return id;
	}
	public Course(long id, String title) {
		super();
		this.id = id;
		this.title = title;
	}
	
	@Override
	public String toString() {
		return "Object[id="+id+", Title="+title+"\n";
	}
	
	private long id;
	private String title;
}
