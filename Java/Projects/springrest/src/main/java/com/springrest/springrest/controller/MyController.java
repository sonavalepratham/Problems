package com.springrest.springrest.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;
import com.springrest.springrest.services.*;

import com.springrest.springrest.controller.entity.*;

@RestController
public class MyController {

	@Autowired
	CourseService obj;
	
	// Hello world
	@GetMapping("/home")
	public String home() {
		return "Hello";
	}
	
	// get all courses
	@GetMapping("/courses")
	public List<Course> getCourses() {
		return obj.getCourses();
	}
	
	//get single course with provided id
	@GetMapping("/course/{courseId}")
	public Course getCourse(@PathVariable String courseId) {
		return obj.getCourse(Long.parseLong(courseId));
	}
	
	// add course
	@PostMapping("/course")
	public Course addCourse(@RequestBody Course c) {
		return obj.addCourse(c);
	}
}
