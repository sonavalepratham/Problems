package com.springrest.springrest.services;

import java.util.ArrayList;
import java.util.List;

import org.springframework.stereotype.Service;

import com.springrest.springrest.controller.entity.Course;

@Service
public class CourseServiceImpl implements CourseService {

	List<Course> lst;
	
	public CourseServiceImpl() {
		lst = new ArrayList<Course>();
		lst.add(new Course(1,"Vishay Hard"));
		lst.add(new Course(2,"Nivant"));
	}
	
	@Override
	public List<Course> getCourses() {
		// TODO Auto-generated method stub
		return lst;
	}

	@Override
	public Course getCourse(long id) {
		// TODO Auto-generated method stub
		for(Course c : lst) {
			if(c.getId() == id)
				return c;
		}
		return null;
	}

	@Override
	public Course addCourse(Course c) {
		// TODO Auto-generated method stub
		lst.add(c);
		return c;
	}

}
