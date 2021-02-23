#include <string>
#include <vector>

#include "student.h"

Student::Student(std::string studentID, std::string firstName, std::string lastName,
				 std::string emailAddress, int studentAge, std::vector<int> daysToCompleteCourses,
				 std::string degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->daysToCompleteCourses = daysToCompleteCourses;
	this->degreeProgram = degreeProgram;

	return;
}

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

void Student::SetdaysToCompleteCourses(std::vector<int> &daysToCompleteCourses) {
	this->daysToCompleteCourses = daysToCompleteCourses;

	return;
}

void Student::SetDegreeProgram(std::string degreeProgram) {
	this->degreeProgram = degreeProgram;

	return;
}

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

std::vector<int> Student::GetDaysToCompleteCourses() const {	
	return this->daysToCompleteCourses;
}

std::string Student::GetDegreeProgram() const {
	return this->degreeProgram;
}