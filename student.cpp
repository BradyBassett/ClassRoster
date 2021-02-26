#include <string>
#include <iostream>

#include "student.h"

// Constructor
Student::Student(std::string studentID, std::string firstName, std::string lastName,
				 std::string emailAddress, int studentAge, int daysInCourse1,
				 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse3 = daysInCourse3;
	this->degreeProgram = degreeProgram;

	return;
}

// Mutators
void Student::SetStudentID(std::string studentID) {
	this->studentID = studentID;

	return;
}

void Student::SetFirstName(std::string firstName) {
	this->firstName = firstName;

	return;
}

void Student::SetLastName(std::string lastName) {
	this->lastName = lastName;

	return;
}

void Student::SetEmailAddress(std::string lastName) {
	this->emailAddress = emailAddress;

	return;
}

void Student::SetStudentAge(int studentAge) {
	this->studentAge = studentAge;
	
	return;
}

void Student::SetDaysInCourses(int course1, int course2, int course3) {
	this->daysInCourse1 = course1;
	this->daysInCourse2 = course2;
	this->daysInCourse3 = course3;

	return;
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;

	return;
}

// Accessors
std::string Student::GetStudentId() const {
	return this->studentID;
}

std::string Student::GetFirstName() const {
	return this->firstName;
}

std::string Student::GetLastName() const {
	return this->lastName;
}

std::string Student::GetEmailAddress() const {
	return this->emailAddress;
}

int Student::GetStudentAge() const {
	return this->studentAge;
}

int Student::GetDaysInCourse1() const {	
	return this->daysInCourse1;
}

int Student::GetDaysInCourse2() const {
	return this->daysInCourse2;
}

int Student::GetDaysInCourse3() const {
	return this->daysInCourse3;
}

DegreeProgram Student::GetDegreeProgram() const {
	return this->degreeProgram;
}

// Function to print out all of a students associated data
void Student::Print() const {
	int courses[]{ this->daysInCourse1, this->daysInCourse2, this->daysInCourse3 };

	std::cout << "StudentID: " << this->studentID << std::endl;
	std::cout << "Student Name: " << this->firstName << " " << this->lastName << std::endl;
	std::cout << "Student Email Address: " << this->emailAddress << std::endl;
	std::cout << "Student Age: " << this->studentAge << std::endl;
	std::cout << "Days in Each Course: " << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << "Course " << i + 1 << ": " << courses[i] << std::endl;
	}
	switch (this->degreeProgram){
		case 1:
			std::cout << "Degree Program: Security" << std::endl;
			break;
		case 2:
			std::cout << "Degree Program: Network" << std::endl;
			break;
		case 3:
			std::cout << "Degree Program: Software" << std::endl;
			break;
	}
	return;
}